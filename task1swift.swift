/**
 * task1swift.swift
 * Hannah Soria
 * 4/24/2024
 * word counter that reads in a file and finds the frewuency of the words and prints the top 20 frequencies
 * 
 */

 import Foundation // gives the needed file reading abilities

 var FreqDict = [String:Int]() // dictionnary to store the words and frequencies

 let filePath = "wctest.txt" // get the file path from command line

 // handle each word in the file
 if let text = try? String(contentsOfFile: filePath, encoding: .utf8){ //try?: returns an optiona, contentsoffile: path to the file, encoding: interpret the file's contents
    let words = text.components(separatedBy: .whitespacesAndNewlines) // text contians entire file contents, then string is split into an array separate by white space to locate words
    for word in words where !word.isEmpty{ // loop through every word in the file that is not empty
        let updated_word = word.lowercased().trimmingCharacters(in: .punctuationCharacters) // make every word lowercase and remove any punctuation


        if let count = FreqDict[updated_word]{ // if this word exists in dictionary
            FreqDict[updated_word] = count + 1 // incrememnt the frequency count
        } else { // if this word does not exist in the dictionary
            FreqDict[updated_word] = 1 // set the frequency count to 1
        }
    }

    let sortedFreqs = FreqDict.sorted { $0.value > $1.value } // array of key value pairs, sort the array by frequency (values in dictionary)
    
    // Print out the top 20 highest values in order
    for (word, frequency) in sortedFreqs.prefix(20) { // do the following for the first 20 elements
        print("Word:\(word)   \t\tFrequency: \(frequency)") // print the word and frequency
    }
} 
 