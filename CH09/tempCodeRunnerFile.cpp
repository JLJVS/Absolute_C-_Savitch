 cout << wordCount << " words" << endl;
    for (int index{}; index < SIZE; index++){
        if (letter_count[index] > 0){
            cout << letter_count[index] << " "  << (char) ('a' + index) << endl; 
        }
    }