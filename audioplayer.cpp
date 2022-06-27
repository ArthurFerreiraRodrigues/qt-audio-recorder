#include "audioplayer.h"

#include <QWidget>
#include <QMediaPlayer>
#include <QAudio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <QUrl>

/*
AudioPlayer::AudioPlayer(QWidget *parent)
    : QWidget(parent)
{
    m_audioPlayer.setMedia(QUrl::fromLocalFile("/home/tz/Music/Playback/response_audio.wav"));
    m_audioPlayer.setVolume(50);

    //connect(m_audioPlayer, &AudioPlayer::stateChanged(QSound::isFinished()), this, &AudioPlayer::onStateChanged);
}

AudioPlayer::togglePlayPause()
{   
    if(m_audioPlayer.state() == QMediaPlayer::StoppedState){
        m_audioPlayer.play();
    }else{
        m_audioPlayer.stop();
    }
}

void AudioPlayer::onStateChanged(QMediaPlayer::State state)
{
    switch(state){
    case QMediaPlayer::PlayingState:
        ui->playButton.setText(tr("Stop"));
        break;
    case QMediaPlayer::StoppedState:
        ui->playButton.setText(tr("Play last recording"));
        break;
    }
}
*/
