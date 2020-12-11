import 'package:flutter/material.dart';
import 'MainPage.dart';
import 'Repository.dart';
import 'Song.dart';

class EditPage extends StatefulWidget {
  final Song song;
  final Repository repo;

  EditPage({Key key, @required this.song, this.repo}) : super(key: key);

  @override
  _EditPageState createState() => _EditPageState();
}

class _EditPageState extends State<EditPage> {
  final titleTF = TextEditingController();

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
                Text("Edit the song", style: TextStyle(fontSize: 50)),
                Text(widget.song.artist + " - " + widget.song.title, style: TextStyle(fontSize: 20)),
                TextField(
                  controller: titleTF,
                  decoration: InputDecoration(
                    border: OutlineInputBorder(),
                    labelText: 'New title',
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
                      widget.repo.editSong(widget.song, titleTF.text);
                      print(widget.repo.songs);
                      Navigator.push(
                        ctxt,
                        new MaterialPageRoute(builder: (ctxt) => MainPage()),
                      );
                    },
                    child: Text("Done", style: TextStyle(fontSize: 20)),
                  ),
                ),
              ],
            )
        )




    );
  }
}