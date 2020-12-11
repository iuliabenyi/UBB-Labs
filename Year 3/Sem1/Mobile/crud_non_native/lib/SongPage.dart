import 'package:flutter/material.dart';
import 'MainPage.dart';
import 'EditPage.dart';
import 'Repository.dart';
import 'Song.dart';

class SongPage extends StatefulWidget {
  final Song song;
  final Repository repo;
  SongPage({Key key, @required this.song, this.repo}) : super(key: key);

  @override
  _SongPageState createState() => _SongPageState();
}

class _SongPageState extends State<SongPage> {
  @override
  Widget build (BuildContext ctxt) {
    return new Scaffold(
      appBar: new AppBar(
        title: new Text("Music app"),
      ),
      body: Center(
        child: new Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Icon(Icons.audiotrack, size: 300),
            Text(widget.song.title, style: TextStyle(fontSize: 60)),
            Text(widget.song.artist, style: TextStyle(fontSize: 30)),
            new Row(
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              children: [
                ButtonTheme(
                  minWidth: 150.0,
                  height: 60.0,
                  child: OutlineButton(
                    highlightedBorderColor: Colors.black.withOpacity(0.12),
                    shape: new RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(26.0),
                    ),
                    onPressed: () {
                      Navigator.push(
                        ctxt,
                        new MaterialPageRoute(builder: (ctxt) => EditPage(song: widget.song, repo: widget.repo)),
                      );
                    },
                    child: Text("Edit", style: TextStyle(fontSize: 20)),
                  ),
                ),
                ButtonTheme(
                  minWidth: 150.0,
                  height: 60.0,
                  child: OutlineButton(
                    highlightedBorderColor: Colors.black.withOpacity(0.12),
                    shape: new RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(26.0),
                    ),
                    onPressed: () {
                      Widget yesButton = FlatButton(
                        child: Text("Yes"),
                        onPressed:  () {
                          widget.repo.deleteSong(widget.song);
                          print(widget.repo.songs);
                          Navigator.push(
                            ctxt,
                            new MaterialPageRoute(builder: (ctxt) => MainPage()),
                          );
                        },
                      );
                      Widget noButton = FlatButton(
                        child: Text("No"),
                        onPressed:  () {
                          Navigator.push(
                            ctxt,
                            new MaterialPageRoute(builder: (ctxt) => MainPage()),
                          );
                        },
                      );
                      // set up the AlertDialog
                      AlertDialog alert = AlertDialog(
                        title: Text("Confirm delete"),
                        content: Text("Would you like to delete " + widget.song.artist + " - " + widget.song.title + "?"),
                        actions: [
                          yesButton,
                          noButton,
                        ],
                      );
                      // show the dialog
                      showDialog(
                        context: ctxt,
                        builder: (BuildContext context) {
                          return alert;
                        },
                      );
                    },
                    child: Text("Delete", style: TextStyle(fontSize: 20)),
                  ),
                ),
              ],
            )
          ],
        )
      )




    );
  }
}