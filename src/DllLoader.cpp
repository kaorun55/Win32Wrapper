/** @file
 * @brief DLL動的ロードサポートクラスの定義
 *
 * @author 中村  薫
 * $Date: 2004/11/20 05:21:49 $
 * $Revision: 1.2 $
 */
#include "win32/DllLoader.h"
#include "win32/Win32Exception.h"

/// Win32ラッパークラス群
namespace win32
{

/**
 *コンストラクタ
 */
DllLoader::DllLoader()
    : dll_()
{
}

/**
 * コンストラクタ
 *
 * @param lpDllName DLLファイル名
 *
 * @exception Win32Exception
 */
DllLoader::DllLoader( LPCTSTR dllName )
    : dll_()
{
    // DLLを開く
    open( dllName );
}

/**
 * デストラクタ
 */
DllLoader::~DllLoader()
{
    close();
}

/**
 * DLLのオープン
 *
 * @param lpDllName DLLファイル名
 *
 * @exception Win32Exception
 *
 * @pre DLL未作成
 */
// DLLのオープン
void DllLoader::open( LPCTSTR dllName )
{
    dll_ = std::shared_ptr< HINSTANCE__ >( ::LoadLibrary( dllName ), &::FreeLibrary );
    if( dll_.get() == 0 ) {
		throw Win32Exception( ::GetLastError() );
	}
}

/**
 * DLLのクローズ
 */
void DllLoader::close()
{
    dll_.reset();
}

// DLLのオープン状態
bool DllLoader::isOpen() const
{
    return dll_.get() != 0;
}

} // namespace win32
// EOF
