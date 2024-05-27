/**
 * task2swift.swift
 * Hannah Soria
 * 4/25/2024
 * examples of swift handling reading and writing to files
 * 
 */

 import Foundation

// reading from a file
 if let fileContents = try? String(contentsOfFile: "wctest.txt"){
    print(fileContents)
    // swift automatically handles closing a file
 } else {
    print("unable to read file")
 }

// writing to a file
 let input = "hello world"
 try input.write(toFile: "output.txt", atomically: true, encoding: .utf8)
 print("write to file was successful")

// accessing URLs
if let url = URL(string: "https://cs.colby.edu"){
    let data = try? Data(contentsOf: url)
    // can do stuff with data here
} else {
    print("invalid URL input")
}

// interactive input
print("hello, what is your name?")
if let name = readLine() {
    print("nice to meet you, \(name)")
}
    