#ifndef DESKTOP_H_INCLUDE
#define DESKTOP_H_INCLUDE

// MFC使用時用にはwindows.hはインクルードしない
#if !defined( __AFXWIN_H__ )
 #include <windows.h>
#endif  // !defined( __AFXWIN_H__ )

#include <memory>

namespace std {
	using namespace std::tr1;
}

namespace win32 {
	class Desktop
	{
	public:

		Desktop();
		~Desktop();

		// 指定されたスレッドIDに関連付けられているデスクトップを開く
		void OpenThreadDesktop( DWORD dwThreadId );

		// デスクトップを閉じる
		void Close();

		// デスクトップを切り替える
		void Switch();

		// 妥当性を確認する
		bool IsValid() const;

	private:

		// ハンドルを閉じる
		static void CloseDesktop( HDESK hDesktop );

		// ハンドルを閉じる(GetThreadDesktop用に何もしない)
		static void DummyCloseDesktop( HDESK hDesktop );

	private:

		typedef std::shared_ptr<HDESK__> Handle;
		Handle handle_;			//< デスクトップハンドル
	};
} // namespace win32

#endif // #ifndef DESKTOP_H_INCLUDE
// EOF
