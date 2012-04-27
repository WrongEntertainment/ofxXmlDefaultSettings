/*
 *  ofxXmlDefaultSettings.cpp
 *  Created by Paul Vollmer, http://www.wng.cc
 *  
 *  Copyright (c) 2012 openFrameworks. All rights reserved.
 *  
 *  The MIT License
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 *
 *  
 *  @testet_oF          0.07
 *  @testet_plattform   MacOs 10.6
 *                      ??? Win
 *                      ??? Linux
 *  @Dependencies       ofxXmlSettings
 *  @modified           2012.04.27
 *  @version            0.1.0
 */

#include "ofxXmlDefaultSettings.h"


	
ofxXmlDefaultSettings::ofxXmlDefaultSettings(){
	// Set our default filename.
	// if init(string filename) will be called, 
	// the string set to new name.
	filename = "ofCoreSettings.xml";
}
	
	
	
/**
 * init
 * check if a default xml file exist.
 * if not, generate one.
 *
 * @param filename
 *        Name of our default xml file.
 */
void ofxXmlDefaultSettings::init(string filename){
	this->filename = filename;
	if(load()){
		ofLogVerbose("Default XML loaded!");
	}else{
		ofLogVerbose("Unable to load Default XML. create a default XML file!");
		createDefaultXml();
		load();
	}
}

void ofxXmlDefaultSettings::init(){
	init(filename);
}



/**
 * L	oad the default xml file.
 */
bool ofxXmlDefaultSettings::load(){
	return loadFile(ofFilePath::getCurrentWorkingDirectory()+"/"+filename);
}


/**
 * save
 */
bool ofxXmlDefaultSettings::save(){
	return saveFile(ofFilePath::getCurrentWorkingDirectory()+"/"+filename);
}


/**
 * setSettings
 * set the openFrameworks core settings from xml content.
 */
void ofxXmlDefaultSettings::setSettings(){
	ofSetFrameRate(getValue("ofGetFrameRate", 60, 0));
	ofSetWindowShape(getValue("ofGetWidth", 1024, 0), getValue("ofGetHeight", 768, 0));
	ofSetWindowPosition(getValue("ofGetWindowPositionX", 30, 0), getValue("ofGetWindowPositionY", 30, 0));
	cout << "Set Settings from Default Xml file." << endl;
}


/**
 * getSettings
 * get the openFrameworks core settings.
 * save to xml.
 */
void ofxXmlDefaultSettings::getSettings(){
	setValue("ofGetFrameRate", ofGetFrameRate(), 0);
	setValue("ofGetWidth", ofGetWidth(), 0);
	setValue("ofGetHeight", ofGetHeight(), 0);
	setValue("ofGetWindowPositionX", ofGetWindowPositionX(), 0);
	setValue("ofGetWindowPositionY", ofGetWindowPositionY(), 0);
	//setValue("ofGetFullscreen", tempFullscreen, 0);
	//setValue("ofGetCursor", tempCursor, 0);
	save();
	cout << "Get Settings to Default Xml file." << endl;
}


/**
 * private method
 * createDefaultXml
 *
 * we create tags to store the ofCore Settings there.
 * the tags i named like the ofGet... methods 
 * i think this looks good to use. OF syntax as xml tag :) 
 */
void ofxXmlDefaultSettings::createDefaultXml(){
	ofxXmlSettings xml;
	xml.addValue("ofGetFrameRate", 60);
	xml.addValue("ofGetWidth", 1024);
	xml.addValue("ofGetHeight", 768);
	xml.addValue("ofGetWindowPositionX", 30);
	xml.addValue("ofGetWindowPositionY", 30);
	xml.addValue("ofGetFullscreen", false);
	xml.addValue("ofGetCursor", false);
	xml.saveFile(ofFilePath::getCurrentWorkingDirectory()+"/"+filename);
	cout << "Default content generated and Xml file saved!" << endl;
}
