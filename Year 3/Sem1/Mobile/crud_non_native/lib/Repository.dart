import 'package:crud_non_native/Song.dart';

class Repository {
  final List<Song> songs = new List<Song>();


  List<Song> getSongs() {
    return this.songs;
  }

  Song getSong(int position) {
    int ct = 0;
    for(Song song in songs) {
      ct++;
      if(ct == position)
        return song;
    }
    return null;
  }

  bool addSong(Song song) {
    this.songs.add(song);
    return true;
  }

  bool deleteSong(Song song) {
    if(songs.contains(song)){
      songs.remove(song);
      return true;
    }
    else{
      return false;
    }
  }

  bool editSong(Song song, String newTitle) {
    song.setTitle(newTitle);
    return true;
  }

}