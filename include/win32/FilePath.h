/** @file
 * @brief ファイルパス操作クラスの宣言
 *
 * @author 中村  薫
 * $Date: 2004/10/21 11:25:09 $
 * $Revision: 1.1.1.1 $
 */
#if !defined( PATHFILE_H_INCLUDE )
#define PATHFILE_H_INCLUDE

#pragma comment( lib, "shlwapi.lib" )

#include <string>

// MFC使用時用にはwindows.hはインクルードしない
#if !defined( __AFXWIN_H__ )
 #include <windows.h>
#endif  // !defined( __AFXWIN_H__ )

#include <shlwapi.h>

#include "win32/SharedType.h"

/// Win32ラッパークラス群
namespace win32
{

	/// ファイルパス操作
	class FilePath
	{
	public:

		// コンストラクタ
		FilePath();
		FilePath( win32::tstring& strPath );
		FilePath( const FilePath& rhs );

		// デストラクタ
		~FilePath();

		// パスを設定
		void SetPath( const win32::tstring& path );
		FilePath& operator = ( const win32::tstring& path );
		FilePath& operator = ( const TCHAR* path );

		// パスを取得
		const win32::tstring& GetPath() const;

		//// パスの追加
		//BOOL AddPath( const win32::tstring& path );

		//// ファイル名の取得
		//win32::tstring GetFileName() const;

		//// 拡張子の取得
		//win32::tstring GetExtention() const;
		//// 拡張子の変更
		//BOOL RenameExtention( const win32::tstring& strExtention );
		//// 拡張子を付加(既に拡張子がついている時には無効)
		//BOOL AddExtention( const win32::tstring& strExtention );
		//// 拡張子の消去
		//void RemoveExtention();

		//// バックスラッシュを付加(パスの最後にバックスラッシュがある場合は無効)
		//void AddBackslash();
		//// バックスラッシュの削除
		//void RemoveBackslash();

		//// ブランクの消去
		//void RemoveBlanks();

		//// パス(ファイル名)が存在するかどうか
		//BOOL IsExists() const;
		//// パスがディレクトリかどうか
		//BOOL IsDirectory() const;
		//// パスのディレクトリが空かどうか
		//BOOL IsDirectoryEmpty() const;

		//// パスがルートパスかどうか
		//BOOL IsRoot() const;
		//// 同じルートパスかどうか
		//BOOL IsSameRoot( const win32::tstring& strPath ) const;

		//// カレントディレクトリの取得
		//static win32::tstring GetCurrentDirectory();

		//// テンポラリパスの取得
		//static win32::tstring GetTempPath();

		// パス(ファイル名)が存在するかどうか
		static bool IsExists( const win32::tstring& path );

		// ファイルの最後の部分を削除する
		static win32::tstring RemoveFileSpec( const win32::tstring& path );

	private:

		win32::tstring	path_;
	};

} // namespace win32;

#endif  // !defined( PATHFILE_H_INCLUDE )
// EOF
