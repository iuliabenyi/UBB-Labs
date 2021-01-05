package com.example.crudnative

import android.content.Intent
import android.os.Bundle
import android.widget.Button
import android.widget.ListView
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.Domain.Repository
import com.example.Domain.Song
import com.google.android.material.floatingactionbutton.FloatingActionButton

//const val EXTRA_MESSAGE = "com.example.myfirstapp.MESSAGE"
class MainActivity : AppCompatActivity() {

    lateinit var listView : ListView
    lateinit var addBtn : Button
    val repo = Repository()
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        listView = findViewById(R.id.listView)
        addBtn = findViewById(R.id.addBtn)

        listView.adapter = MyListAdapter(this,R.layout.row, repo.songs)

        listView.setOnItemClickListener{parent, view, position, id ->
            val songPage = Intent(applicationContext, SongPage::class.java)
            songPage.putExtra("repo", repo)
            songPage.putExtra("position", position + 1)
            startActivity(songPage)
        }

        addBtn.setOnClickListener {
            val addPage = Intent(applicationContext, AddPage::class.java)
            addPage.putExtra("repo", repo)
            startActivity(addPage)
        }

        listView.adapter = MyListAdapter(this,R.layout.row, repo.songs)

        System.out.println(repo.songs)





    }
}