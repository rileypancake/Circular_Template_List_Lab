// Edited by Riley Pancake on 11/16/26
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_SONG_H
#define CIRCULARTEMPLATEDLIST_SONG_H

#include "Media.h"
#include <iostream>
#include <string>

class Song : public Media {
private:
    std::string artist;

public:
    Song(const std::string& t, const std::string& a, int d)
        : Media(t, d), artist(a) {}

    void play() const override {
        std::cout << "🎵 Now playing: " << title << " by " << artist << " 🎵" << std::endl;
    }

    std::string toString() const override {
        return "Song: " + title + " | Artist: " + artist + " | Duration: " + formatDuration();
    }
};

#endif //CIRCULARTEMPLATEDLIST_SONG_H