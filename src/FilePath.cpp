/** @file
 * @brief ファイルパス操作クラスの定義
 *
 * @author 中村  薫
 * $Date: 2004/10/21 11:25:09 $
 * $Revision: 1.1.1.1 $
 */
#include <vector>

#include "win32/FilePath.h"
#include "win32/Win32Exception.h"

namespace win32 {
	// コンストラクタ
	FilePath::FilePath()
	{
	}

	// コンストラクタ
	FilePath::FilePath( win32::tstring& strPath )
	{
		SetPath( strPath );
	}

	// コンストラクタ
	FilePath::FilePath( const FilePath& rhs )
	{
		SetPath( rhs.path_ );
	}

	// デストラクタ
	FilePath::~FilePath()
	{
	}

	// パスを設定
	void FilePath::SetPath( const win32::tstring& path )
	{
		path_ = path;
	}

	FilePath& FilePath::operator = ( const win32::tstring& path )
	{
		SetPath( path );
		return *this;
	}

	FilePath& FilePath::operator = ( const TCHAR* path )
	{
		SetPath( path );
		return *this;
	}


	// パスを取得
	const win32::tstring& FilePath::GetPath() const
	{
		return path_;
	}

	//// パスの追加
	//BOOL FilePath::AddPath( const win32::tstring& path )
	//{
	//	return ::PathAppend( path_, strPath );
	//}

	//// ファイル名の取得
	//win32::tstring FilePath::GetFileName() const
	//{
	//	return win32::tstring( ::PathFindFileName( path_.c_str() ) );
	//}

	//// 拡張子の取得
	//win32::tstring FilePath::GetExtention() const
	//{
	//	return win32::tstring( ::PathFindExtension( path_.c_str() ) );
	//}

	//// 拡張子の変更
	//BOOL FilePath::RenameExtention( const win32::tstring& strExtention )
	//{
	//	return( ::PathRenameExtension( path_, strExtention ) );
	//}

	//// 拡張子を付加(既に拡張子がついている時には無効)
	//BOOL FilePath::AddExtention( const win32::tstring& strExtention )
	//{
	//	return( ::PathAddExtension( path_, strExtention ) );
	//}

	//// 拡張子の消去
	//void FilePath::RemoveExtention()
	//{
	//	::PathRemoveExtension( path_ );
	//}

	//// バックスラッシュを付加(パスの最後にバックスラッシュがある場合は無効)
	//void FilePath::AddBackslash()
	//{
	//	::PathAddBackslash( path_ );
	//}

	//// バックスラッシュの削除
	//void FilePath::RemoveBackslash()
	//{
	//	::PathRemoveBackslash( path_ );
	//}

	//// ブランクの消去
	//void FilePath::RemoveBlanks()
	//{
	//	::PathRemoveBlanks( path_ );
	//}

	//// パス(ファイル名)が存在するかどうか
	//BOOL FilePath::IsExists() const
	//{
	//	return( ::PathFileExists( path_ ) );
	//}

	// パス(ファイル名)が存在するかどうか
	/*static*/ bool FilePath::IsExists( const win32::tstring& path )
	{
		return ::PathFileExists( path.c_str() );
	}

	//// パスがディレクトリかどうか
	//BOOL FilePath::IsDirectory() const
	//{
	//	return( ::PathIsDirectory( path_ ) );
	//}

	//// パスのディレクトリが空かどうか
	//BOOL FilePath::IsDirectoryEmpty() const
	//{
	//// SDKをアップデートしないと使えない?
	////    return( ::PathIsDirectoryEmpty( path_ ) );
	//	return( FALSE );
	//}

	//// パスがルートパスかどうか
	//BOOL FilePath::IsRoot() const
	//{
	//	return( ::PathIsRoot( path_ ) );
	//}

	//// 同じルートパスかどうか
	//BOOL FilePath::IsSameRoot( const win32::tstring& strPath ) const
	//{
	//	return( ::PathIsSameRoot( path_, strPath ) );
	//}

	//// カレントディレクトリの取得
	///*static*/ win32::tstring FilePath::GetCurrentDirectory()
	//{
	//	TCHAR	path[MAX_PATH] = { 0 };
	//	DWORD ret = ::GetCurrentDirectory( sizeof(path), path );
	//	if ( ret == 0 ) { 
	//		Throw_Win32Exception();
	//	}

	//	return std::string( path );
	//}

	//// テンポラリパスの取得
	///*static*/ win32::tstring FilePath::GetTempPath()
	//{
	//	TCHAR	tempPath[MAX_PATH];
	//	DWORD ret = ::GetTempPath( sizeof(tempPath), tempPath );
	//	if ( ret == 0 ) { 
	//		Throw_Win32Exception();
	//	}

	//	return win32::tstring( tempPath );
	//}

	// ファイルの最後の部分を削除する
	/*static*/ win32::tstring FilePath::RemoveFileSpec( const win32::tstring& path )
	{
		std::vector< win32::tstring::value_type > str( path.begin(), path.end() );
		BOOL ret = ::PathRemoveFileSpec( &str[0] );
		if ( !ret ) {
			Throw_Win32Exception();
		}

		return win32::tstring( &str[0] );
	}
}
// EOF
