#Installation and running of EMDCreator prototype
1> Compile this program with make on terminal.
2> Run the executable.
3> There are three buttons on interface
    a) Load file -> Load the media file for which you want to create EMD text file.
    b) Undo Last cut -> you can undo your last slider click's result on EMD text file.
    c) Crete -> Create EMD text file with SAVE dialog box.

Note: MPlayer as backend is required. This creator's code contain ExMplayer's code.

4> EDITING:
    After file gets loaded (latency depends upon MPlayer)...
    Hover over the slider to look at the scenes in seekview.
    Click to start cut. Click at another place ahead of start to make end.
    Like this pair of clicks will result in set of time intervals where your original file will skip
    when you will play VLC with the EMD file created by this creator.

NOTE:Please revert back if you find any error.
