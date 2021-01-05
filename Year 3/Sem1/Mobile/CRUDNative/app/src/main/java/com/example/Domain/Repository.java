package com.example.Domain;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Repository implements IRepository, Serializable {
    private List<Song> songs = new ArrayList<Song>();

    public Repository() throws IOException {

        songs.add(new Song("title1", "author1"));
        songs.add(new Song("title2", "author2"));
        songs.add(new Song("title3", "author3"));
        songs.add(new Song("title4", "author4"));
        songs.add(new Song("title5", "author5"));
        songs.add(new Song("title6", "author6"));
        songs.add(new Song("title7", "author7"));
        songs.add(new Song("title8", "author8"));
        songs.add(new Song("title9", "author9"));
        songs.add(new Song("title10", "author10"));

    }


    @Override
    public List<Song> getSongs() {
        return this.songs;
    }

    @Override
    public Song getSong(int position) {
        int ct = 0;
        for(Song song : songs) {
            ct++;
            if(ct == position)
                return song;
        }
        return null;
    }

    @Override
    public boolean addSong(Song song) {
        this.songs.add(song);
        return true;
    }

    @Override
    public boolean deleteSong(Song song) {
        if(songs.contains(song)){
            songs.remove(song);
            return true;
        }
        else{
            return false;
        }
    }

    @Override
    public boolean editSong(Song song, String newTitle) {
        song.setTitle(newTitle);
        return true;
    }
}
