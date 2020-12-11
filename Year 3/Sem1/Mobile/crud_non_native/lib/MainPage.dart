import 'package:crud_non_native/SongPage.dart';
import 'package:flutter/material.dart';
import 'SongPage.dart';
import 'AddPage.dart';
import 'Repository.dart';
import 'Song.dart';

class MainPage extends StatefulWidget {
  @override
  _MainPageState createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {
  @override
  Widget build (BuildContext ctxt) {
    Repository repo = new Repository();
    repo.addSong(new Song("Title1", "Artist1"));
    repo.addSong(new Song("Title2", "Artist2"));
    repo.addSong(new Song("Title3", "Artist3"));
    repo.addSong(new Song("Title4", "Artist4"));
    repo.addSong(new Song("Title5", "Artist5"));
    final songs = repo.songs;
    return new Scaffold(
        appBar: new AppBar(
          title: new Text("Music app"),
        ),
        body: new ListView.builder(
          itemCount: songs.length,
          itemBuilder: (context, index) {
            return ListTile(
              title: Text(songs[index].title, style: DefaultTextStyle.of(context).style.apply(fontSizeFactor: 2.0)),
              subtitle: Text(songs[index].artist, style: DefaultTextStyle.of(context).style.apply(fontSizeFactor: 1.2),),
              onTap: () {
                Navigator.push(
                  ctxt,
                  new MaterialPageRoute(builder: (context) => SongPage(song: songs[index], repo: repo)),
                );
              },
            );
          },
        ),
        floatingActionButton: FloatingActionButton(
        onPressed: () {
          Navigator.push(
            ctxt,
            new MaterialPageRoute(builder: (context) => AddPage(repo: repo)),
          );
        },
        child: Icon(Icons.add),
    backgroundColor: Colors.green,
    ),
    );
  }
}
