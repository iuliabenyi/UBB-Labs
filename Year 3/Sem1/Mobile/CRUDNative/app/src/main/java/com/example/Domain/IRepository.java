package com.example.Domain;

import java.util.List;

public interface IRepository {
    List<Song> getSongs();
    Song getSong(int position);
    boolean addSong(Song song);
    boolean deleteSong(Song song);
    boolean editSong(Song song, String newTitle);
}
