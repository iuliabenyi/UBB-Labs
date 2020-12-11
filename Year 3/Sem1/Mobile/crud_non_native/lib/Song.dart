class Song {
  String title;
  String artist;

  Song(this.title, this.artist);

  String getTitle() {
    return title;
  }

  void setTitle(String title) {
    this.title = title;
  }

  String getArtist() {
    return artist;
  }

  void setArtist(String artist) {
    this.artist = artist;
  }

  String toString() {
    return this.artist.toString() + " - " + this.title.toString();
  }


}