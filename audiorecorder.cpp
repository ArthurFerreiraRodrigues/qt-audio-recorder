/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "audiorecorder.h"
#include "audiolevel.h"

#include "ui_audiorecorder.h"

#include <QAudioProbe>
#include <QAudioRecorder>
#include <QMovie>
#include <QDir>
#include <QFileDialog>
#include <QMediaRecorder>

#include <QStandardPaths>

AudioRecorder::AudioRecorder()
    : ui(new Ui::AudioRecorder)
{
    ui->setupUi(this);

    m_audioRecorder = new QAudioRecorder(this);


    // Iniciando objetos de audio
    m_audioPlayer.setMedia(QUrl::fromLocalFile("/home/tz/Music/Playback/response_audio.wav"));
    m_audioPlayer.setVolume(50);

    //Adicionando GIF a tela inicial
    QMovie *gif = new QMovie(":/assets/images/robot.gif");
    ui->gifLabel->setMovie(gif);
    gif->start();




    connect(m_audioRecorder, &QAudioRecorder::durationChanged, this, &AudioRecorder::updateProgress);
    connect(m_audioRecorder, &QAudioRecorder::statusChanged, this, &AudioRecorder::updateStatus);
    connect(m_audioRecorder, &QAudioRecorder::stateChanged, this, &AudioRecorder::onStateChanged);
    connect(m_audioRecorder, QOverload<QMediaRecorder::Error>::of(&QAudioRecorder::error), this,
            &AudioRecorder::displayErrorMessage);
}

void AudioRecorder::updateProgress(qint64 duration)
{
    if (m_audioRecorder->error() != QMediaRecorder::NoError || duration < 2000)
        return;

    ui->statusbar->showMessage(tr("Recorded %1 sec").arg(duration / 1000));
}

void AudioRecorder::updateStatus(QMediaRecorder::Status status)
{
    QString statusMessage;

    switch (status) {
    case QMediaRecorder::RecordingStatus:
        statusMessage = tr("Recording to %1").arg(m_audioRecorder->actualLocation().toString());
        break;
    case QMediaRecorder::UnloadedStatus:
    case QMediaRecorder::LoadedStatus:
        statusMessage = tr("Stopped");
    default:
        break;
    }

    if (m_audioRecorder->error() == QMediaRecorder::NoError)
        ui->statusbar->showMessage(statusMessage);
}

void AudioRecorder::onStateChanged(QMediaRecorder::State state)
{
    switch (state) {
    case QMediaRecorder::RecordingState:
        ui->recordButton->setText(tr("Stop"));
        break;
    case QMediaRecorder::StoppedState:
        ui->recordButton->setText(tr("Record"));
        break;
    case QMediaRecorder::PausedState:
        break;

    }
}

void AudioRecorder::toggleRecord()
{
    if (m_audioRecorder->state() == QMediaRecorder::StoppedState) {
        m_audioRecorder->setAudioInput("");

        QAudioEncoderSettings settings;

        settings.setCodec("");
        settings.setSampleRate(0);
        settings.setBitRate(0);
        settings.setChannelCount(-1);
        settings.setQuality(QMultimedia::EncodingQuality(4));
        settings.setEncodingMode(QMultimedia::ConstantQualityEncoding);

        // container é o formato do arquivo
        QString container = "audio/x-wav";

        m_audioRecorder->setEncodingSettings(settings, QVideoEncoderSettings(), container);
        m_audioRecorder->record();
    }
    else {
        m_audioRecorder->stop();
    }
}



void AudioRecorder::displayErrorMessage()
{
    ui->statusbar->showMessage(m_audioRecorder->errorString());
}

// PLAYER

void AudioRecorder::togglePlayPause()
{
   if(m_audioPlayer.state() == QMediaPlayer::StoppedState){
       m_audioPlayer.play();

   }else{
       m_audioPlayer.stop();
   }
   onPlayerStateChanged(m_audioPlayer.state());
}

void AudioRecorder::onPlayerStateChanged(QMediaPlayer::State state)
{
    switch(state){
    case QMediaPlayer::PlayingState:
        ui->playButton->setText(tr("Stop"));
        break;
    case QMediaPlayer::StoppedState:
        ui->playButton->setText(tr("Play last recording"));
        break;

    case QMediaPlayer::PausedState:
        break;
    }
}
