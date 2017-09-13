#ifndef ITFILEMANAGER_H_
#define ITFILEMANAGER_H_

class itFileManager
{
private:
	itFileManager() {}
	~itFileManager() {}

public:
	static itFileManager* getInstance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new itFileManager();
		}
		return m_instance;
	}
	static void kill()
	{
		if (m_instance != nullptr)
		{
			delete m_instance;
			m_instance = nullptr;
		}
	}
	void loadResources();
private:
	static itFileManager *m_instance;
};

#endif // !ITFILEMANAGER_H_

