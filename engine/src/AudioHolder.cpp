//
// Created by Severin on 04.03.2023.
//

#include "engine/AudioHolder.h"

#include <SDL_audio.h>

namespace engine {
    struct AudioHolder::Audio{
        SDL_AudioDeviceID deviceId;
        SDL_AudioSpec audioSpec;
        Uint8* waveStart;
        Uint32 waveLength;
    };

    void AudioHolder::Load(const std::string& file, const std::string& id) {
        std::unique_ptr<Audio> audio = std::make_unique<Audio>();

        if (!SDL_LoadWAV(file.c_str(), &audio->audioSpec, &audio->waveStart, &audio->waveLength))
            throw std::runtime_error("Can't load audio file: " + file);

        audio->deviceId = SDL_OpenAudioDevice(nullptr, 0,
                                              &audio->audioSpec, nullptr,
                                              SDL_AUDIO_ALLOW_ANY_CHANGE);

        if (!audio->deviceId)
            throw std::runtime_error("Can't open audio device.");

        map[id] = std::move(audio);
    }

    void AudioHolder::Unload(const std::string& id) {
        SDL_PauseAudioDevice(map[id]->deviceId, SDL_TRUE);
        SDL_FreeWAV(map[id]->waveStart);
        map.erase(id);
    }

    AudioHolder::~AudioHolder() {
        for (auto& i: map) {
            SDL_FreeWAV(i.second->waveStart);
        }
    }

    AudioHolder::AudioHolder() = default;

    void AudioHolder::Play(const std::string& id) {
        SDL_QueueAudio(map[id]->deviceId, map[id]->waveStart, map[id]->waveLength);
        SDL_PauseAudioDevice(map[id]->deviceId, SDL_FALSE);
    }

    void AudioHolder::Stop(const std::string& id) {
        SDL_PauseAudioDevice(map[id]->deviceId, SDL_TRUE);
    }
} // engine