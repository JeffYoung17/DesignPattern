/**
 * breif: FileSplitter是一个Subject,Iprogress作为通知机制对观察者进行通知
 */
class IProgress {
public:
	virtual void DoProgress(float value) = 0;
	virtual ~IProgress();
}

class FileSplitter
{
	string m_filePath;
	int m_fileNumber;
	// ProgressBar* m_progressBar; // 具体的通知控件
	IProgress* m_iprogress; // 抽象的通知机制

public:
	FileSplitter(const string& filePath, int fileNumber, IProgress* iprogress) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber),
		m_iprogress(iprogress){

	}

	void split(){
		//1.读取大文件

		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue);
		}
	}

protected:
	virtual void onProgress(float value) {
		if (m_iprogress != nullptr) {
			m_iprogress->DoProgress(value);
		}
	}
};