package com.example

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import com.example.Domain.Repository
import com.example.Domain.Song
import com.example.crudnative.R

class EditPage : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_edit_page)

        lateinit var doneBtn : Button
        lateinit var songDetails : TextView

        var repo = intent.extras?.get("repo") as Repository
        var position = intent.extras?.get("position") as Int

        doneBtn = findViewById(R.id.doneBtn)
        songDetails = findViewById(R.id.songDetails)
        songDetails.hint = repo.getSong(position).author + " - " + repo.getSong(position).title
        val title : EditText = findViewById(R.id.titleTv)
        doneBtn.setOnClickListener {
            repo.editSong(repo.getSong(position), title.text.toString())
            System.out.println(repo.songs.toString())
            finish()
        }

    }
}