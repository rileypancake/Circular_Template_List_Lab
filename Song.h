//
// Created by Christopher Vaughn on 10/24/25.
// Edited by Riley Pancake at 11/16/26
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

    std::string getArtist() const;

    void play() const override;
    std::string toString() const override;
};

#endif //CIRCULARTEMPLATEDLIST_SONG_H