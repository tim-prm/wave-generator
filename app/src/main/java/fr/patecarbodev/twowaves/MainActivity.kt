package fr.patecarbodev.twowaves

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import fr.patecarbodev.twowaves.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        startEngine()

        // Set up buttons.
        val button440 = binding.button440
        val button660 = binding.button660

        button660.setOnClickListener {
            updateFrequency(660.0) }
        button440.setOnClickListener {
            updateFrequency(440.0) }



    }

    private external fun startEngine()

    private external fun updateFrequency(buttonValue: Double)

    private external fun stopEngine()

    companion object {
        // Used to load the 'twowaves' library on application startup.
        init {
            System.loadLibrary("twowaves")
        }
    }
}