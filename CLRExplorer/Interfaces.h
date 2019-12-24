#pragma once

enum class NodeType {
	Root,
	Summary,
	AppDomains,
	AllAssemblies,
	AllModules,
	ThreadPool,
	Threads
};

struct IGenericListViewCallback {
	virtual int GetItemCount() = 0;
	virtual bool Init(CListViewCtrl& lv) = 0;
	virtual CString GetItemText(int row, int col) = 0;
	virtual int GetIcon(int row) {
		return -1;
	}
	virtual bool Sort(int column, bool ascending) = 0;
	virtual bool CanSort(int column) const {
		return true;
	}
	virtual void OnContextMenu(const POINT& pt, int selected) {}
	virtual void ExecuteCommand(WORD id) {}
	virtual bool CanExecuteCommand(WORD id) {
		return true;
	}
};

struct IToolBarProvider {
	virtual bool Init(CToolBarCtrl& tb) = 0;
	virtual bool OnCommand(WORD id) = 0;
};

struct IMainFrame {
	virtual int FindTab(DWORD_PTR data) = 0;
	virtual void SwitchToPage(int page) = 0;
	virtual void AddTab(DWORD_PTR type) = 0;
};