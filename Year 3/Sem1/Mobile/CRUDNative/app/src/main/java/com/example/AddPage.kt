package com.example.crudnative

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import com.example.Domain.Repository
import com.example.Domain.Song

class AddPage : AppCompatActivity() {

    //var repo = Repository()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_add_page)

        lateinit var doneBtn : Button

        var repo = intent.extras?.get("repo") as Repository

        doneBtn = findViewById(R.id.doneBtn)
        val title : EditText = findViewById(R.id.titleTv)
        val artist : EditText = findViewById(R.id.artistTv)
        doneBtn.setOnClickListener {
            repo.addSong(Song(title.text.toString(), artist.text.toString()))
            System.out.println(repo.songs.toString())
            finish()
        }
    }
}