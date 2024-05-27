/**
 * haiku.swift
 * Hannah Soria
 * 4/25/2024
 * haiku demonstrating file I/O
 */
import Foundation
 // reading from a file
 if let haiku = try? String(contentsOfFile: "haiku.txt"){
    print(haiku)
 }