Cursor Movements:
    h = left
    j = down
    k = up
    l = right

vim commands:
    lesson 1 (Create and Adding txt to a file):
        vim __name__.txt = create a vim editor for the file: __name__.txt
        :q! = exit, DISCARDING any changes you've made
        x   = delete character under cursor
        i   = insert txt
        A   = append txt
        :wq = save and exit file

    lesson 2 (Deleting and Undoing mistakes):
        d = delete operator
        motion = what the operator will do
        Ex, the [] is used to show what is motion, actual command is without the []:
            d[w]  = delete a word.
            d[$]  = delete the rest of the line.
            d[e]  = delete from the cursor to the end of word.
            dd = delete whole line

        count = number of time a motion will repeats
        Ex [] specify what count is, actual command does not include []:
            [2]w = move cursor 2 words forward
            [3]e = move cursor to the end of the third word
            [0]  = move cursor to the start of line.

        u = undo
        U = undo whole line

        CTRL+R = redo the undo commands

    lesson 3 (changing/editing content of file): 
        p = put deleted text after the cursor
        r = repalce character
        c = change character
            ce = change fomr the cursor to the end of word
            c$ = change to end of the a line.
        
    lesson 4 (Search and substitude):
        CTRL + G    = display current locationg in file / file status
        G           = move to end of the file
        [#]G        = move to that line number
        gg          = move to the first line.

        /__pharse__ = search for __pharse__ FORWARDS
        ?__pharse__ = search for __pharse__ BACKWARDS
        n           = find the next occurrence of __pharse__ in the following the same direction.
        N           = find the next occurrence of __pharse__ in the opposite direction.
        CTRL + O    = go back to older positions
        CTRL + I    = go to newer positions.

        %           = find the matching (), [], or {}

        :s/old/new      = substitude old word for new word.
        :s/old/new/g    = substitude old word for new word globally
        :#,#s/old/new/g = substitude phrases between 2 lines (Ex: 1,3s/old/new/g = substitude phrases between line 1 and 3)
        :%s/old/new/g   = substitude all occurrence in the file
        :%s/old/new/gc  = ask for substitude confirmation before it is carried out.

    lesson 5 (External commands):
        :!command = executes an external command.
            [:!ls] or [:!dir]                    = show directory listing
            [!del __name__] or [!rs __name__]    = removes file, __name__

        :w __name__ = write the current vim file to disk with name: __name__
        
        v           = used to select txt visually.
            v motion :w __name__ = save visually selected lines in file: __name__
        
        :r __name__ = retrieves disk file __name__ and puts it below cursor.
        :r !dir     = read the output of the dir command and puts it below the cursor postion.
    
    lesson 6:
        o   = create line BELOW cursor and enter Insert mode.
        O   = create line ABOVE cursor and enter Insert mode.
        
        a   = insert text AFTER cursor
        A   = insert text after the end of the line.

        e   = move to the end of a word
        
        y   = copy text
        p   = past text

        R   = enter replace mode

        :set xxx    = set the option "xxx"
            :set ic     = ignore case, upper/lower case not considered when searching.
            :set is     = incsearch, shows partial matches for a search phrase.
            :set hls    = hlsearch, highlights all matching phrases.

        :set [no]xxx = switch option "xxx" off 
            :set noic   = turn off ignore case.
            :set nois   = turn of incsearch.
            :set nohls  = turn of hlsearch.

    lesson 7 (creating start-up script):
        :help __command__ = find out how __command__ works
            :help w
        
        :help cmd       = find help on cmd
        CTRL-W CTRL-W   = jump to another window
        
        :q  = close window
        :