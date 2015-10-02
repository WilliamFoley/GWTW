//Sound.h

#ifndef SOUND
#define SOUND


#include <irrlicht.h>
#include <irrKlang.h>
#include <iostream>
#include <string>


using namespace irr;
using namespace irrklang;
using namespace scene;

using namespace std;

// sound class 
class Sound
{
public:

	Sound();
	Sound(const std::string& fileName);
	~Sound();
	
	//plays the sound once
	void playSoundOnce(bool deleteFile = false);
	
	// sets sound to play
	void playSound();

	void playSound(const std::string& soundLocation);

	void setFileName(const std::string& soundName);

	std::string getFileLocation();

	bool isPlaying();

	// stops the sound from playing
	void stop();

	void pause();


private:
	irrklang::ISoundEngine* engine_;
	irrklang::ISound* csound_;
	std::string fileName_;
	size_t volume_;
	size_t position_;




};

#endif

Sound::Sound() : volume_(50), position_(0), fileName_(""), csound_(0)
{
	engine_ = createIrrKlangDevice();

	if (!engine_)
	{
		exit(0);
	}

}
Sound::Sound(const std::string& fileName)
{
	fileName_ = fileName;
}
Sound::~Sound()
{
	engine_->drop();
	csound_->drop();
}
void Sound::playSound()
{
	csound_ = engine_->play2D(fileName_.c_str(), false, false, true);
}

void Sound::playSound(const std::string& soundLocation)
{
	setFileName(soundLocation);
	csound_ = engine_->play2D(fileName_.c_str(), false, false, true);
}




std::string Sound::getFileLocation()
{

	return fileName_;
}

void Sound::setFileName(const std::string& soundName)
{

	fileName_ = soundName;
}


bool Sound::isPlaying()
{
	return !csound_->isFinished();
}

void Sound::stop()
{
	 engine_->stopAllSounds();
}


void Sound::pause()
{
	engine_->setAllSoundsPaused();
}