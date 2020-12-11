import 'package:crud_non_native/Repository.dart';
import 'package:flutter/material.dart';
import 'MainPage.dart';
import 'Song.dart';

class AddPage extends StatefulWidget {
  final Repository repo;

  AddPage({Key key, @required this.repo}) : super(key: key);

  @override
  _AddPageState createState() => _AddPageState();
}

class _AddPageState extends State<AddPage> {
  final artistTF = TextEditingController();

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
                Text("Add a song", style: TextStyle(fontSize: 50)),
                TextField(
                  controller: titleTF,
                  decoration: InputDecoration(
                    border: OutlineInputBorder(),
                    labelText: 'Title',
                  ),
                ),
                TextField(
                  controller: artistTF,
                  decoration: InputDecoration(
                    border: OutlineInputBorder(),
                    labelText: 'Artist',
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
                      widget.repo.addSong(new Song(artistTF.text, titleTF.text));
                      print(widget.repo.songs);
                      Navigator.push(
                        ctxt,
                        new MaterialPageRoute(builder: (ctxt) => MainPage()),
                      );
                    },
                    child: Text("Add", style: TextStyle(fontSize: 20)),
                  ),
                ),
              ],
            )
        )




    );
  }
}