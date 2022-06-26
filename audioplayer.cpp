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
    m_audioPlayer = new QMediaPlayer;
    m_audioPlayer->setMedia(QUrl::fromLocalFile("~/Music/Playback/response_audio.wav"));
    m_audioPlayer->setVolume(50);
    m_audioPlayer->play();

    connect(m_audioPlayer, &AudioPlayer::stateChanged(QSound::isFinished()), this, &AudioPlayer::onStateChanged);
}

AudioPlayer::togglePlayPause()
{

    namespace fs = std::filesystem;
    const fs::path dir{"~Music/Playback"};

    if(!fs::is_empty(dir)){
        QSound::play("~/Music/Playback/response_audio.wav")
    }


}

void AudioPlayer::onStateChanged(bool finished)
{
    if(finished){
    }
    case QMediaRecorder::RecordingState:
        ui->recordButton->setText(tr("Stop"));
        break;
        ui->recordButton->setText(tr("Stop"));

        break;
    case QMediaRecorder::StoppedState:
        ui->recordButton->setText(tr("Record"));
        break;
    }
}
*/
