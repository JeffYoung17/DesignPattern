/**
 * MainForm,作为观察者
 * 当MainForm的实例对象调用Button1_Click,进行观察
 */
class MainForm : public Form, public IProgress
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		// this是当前对象的指针,派生类指针可以转换为基类IProgress指针
		FileSplitter splitter(filePath, number, this);

		splitter.split();
	}

	virtual void DoProgress(float value) {
		progressBar->setValue(value);
	}
};
