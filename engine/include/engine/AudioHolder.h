//
// Created by Severin on 04.03.2023.
//

#ifndef SHOTGUNKITTY_AUDIOHOLDER_H
#define SHOTGUNKITTY_AUDIOHOLDER_H

#include <string>
#include <map>

namespace engine {

    class AudioHolder {
    public:
        AudioHolder();
        ~AudioHolder();

        void Load(const std::string& file, const std::string& id);
        void Unload(const std::string& id);

        void Play(const std::string& id);
        void Stop(const std::string& id);
    private:
        struct Audio;

        std::map<std::string, std::unique_ptr<Audio>> map;
    };

} // engine

#endif //SHOTGUNKITTY_AUDIOHOLDER_H
