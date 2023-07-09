#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>

class Track
{
private:
	//Private Fields
	std::string m_title;
	std::tm m_lenght {0};
	std::tm m_releaseDate {0};

public:
	//Public Methods

	//title
	std::string get_title()
	{
		return m_title;
	}
	void set_title(std::string track_title)
	{
		m_title = track_title;
	}

	//lenght
	std::tm get_lenght()
	{
		return m_lenght;
	}

	void set_lenght(std::string t_str)
	{
		std::stringstream ss(t_str);
		ss >> std::get_time(&m_lenght, "%M:%S");
	}

	//date
	void set_date(std::string d_str)
	{
		std::stringstream ss(d_str);
		ss >> std::get_time(&m_releaseDate, "%m.%d.%Y");
	}

	std::tm get_date()
	{
		return m_releaseDate;
	}
};

class Player
{
private:
	//Private Fields
	bool m_is_playing = false;

	//Private Methods
	void displayTracks()
	{
		int i = 1;
		for (auto& track : music)
			std::cout << i++ << ". " << track.get_title() << std::endl;
	}

	void startTrack(int trackID)
	{
		if (trackID >= 1 && trackID <= 5)
		{
			std::cout << "Now playing: " << music[trackID].get_title() << " - " << std::put_time(&music[trackID].get_lenght(), "%M:%S") << std::endl;
			std::cout << "Release date: " << std::put_time(&music[trackID].get_date(), "%m.%d.%Y") << std::endl;
			m_is_playing = true;
		}
	}

public:
	//Public Fields
	std::vector<Track> music;

	//Public Methods
	bool is_active()
	{
		return m_is_playing;
	}

	void play()
	{
		displayTracks();
		int input;
		std::cout << "> ";
		std::cin >> input;
		startTrack(input);

	}
	void pause()
	{
		if (m_is_playing)
		{
			std::cout << "Player paused." << std::endl;
		}

	}
	void next()
	{
		if (m_is_playing)
		{
			int rn = rand() % 4 + 1;
			startTrack(rn);
		}
		
	}
	void stop()
	{
		if(m_is_playing)
		{
			std::cout << "Player stopped." << std::endl;
			m_is_playing = false;
		}
	}
};

std::string handleInput()
{
	std::string input;
	std::cout << "> ";
	std::cin >> input;
	
	if (input.length() <= 5)
		return input;
	else
		return "";
}

int main()
{
	Player audioPlayer;


	Track t1;
	t1.set_title("Test1");
	t1.set_lenght("1:11");
	t1.set_date("1.1.2001");
	audioPlayer.music.push_back(t1);

	Track t2;
	t2.set_title("Test2");
	t2.set_lenght("4:23");
	t2.set_date("2.2.2002");
	audioPlayer.music.push_back(t2);

	Track t3;
	t3.set_title("Test3");
	t3.set_lenght("3:33");
	t3.set_date("3.3.2003");
	audioPlayer.music.push_back(t3);

	Track t4;
	t4.set_title("Test4");
	t4.set_lenght("4:44");
	t4.set_date("4.4.2004");
	audioPlayer.music.push_back(t4);

	Track t5;
	t5.set_title("Test5");
	t5.set_lenght("5:55");
	t5.set_date("5.5.2005");
	audioPlayer.music.push_back(t5);

	while (true)
	{
		std::string input = handleInput();
		if (input == "play")
			audioPlayer.play();
		else if (input == "stop")
			audioPlayer.stop();
		else if (input == "pause")
			audioPlayer.pause();
		else if (input == "next")
			audioPlayer.next();
		else 
			std::cout << "Incorrect command." << std::endl;
		std::cin.clear();
	}

	return 0;
}