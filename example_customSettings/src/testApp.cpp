/*
 *  ofxXmlDefaultSettings
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
 *  @modified           2012.04.28
 *  @version            0.1.0a
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	defXML.init("myDefaultSettings.xml");
	defXML.setSettings();
	
	
	int tempVar1, tempVar2, tempVar3;
	
	if (defXML.tagExists("wng", 0)) {
		tempVar1 = defXML.getValue("wng:myVar1", 0, 0);
		tempVar2 = defXML.getValue("wng:myVar2", 0, 0);
		tempVar3 = defXML.getValue("wng:myVar3", 0, 0);
	} else {
		tempVar1 = 100;
		tempVar2 = 200;
		tempVar3 = 300;
		defXML.addTag("wng");
		defXML.pushTag("wng", 0);
		defXML.addValue("myVar1", tempVar1);
		defXML.addValue("myVar2", tempVar2);
		defXML.addValue("myVar3", tempVar3);
		defXML.popTag();
		defXML.saveFile();
	}
	
	ofLog() << "tempVar1 = " << tempVar1;
	ofLog() << "tempVar2 = " << tempVar2;
	ofLog() << "tempVar3 = " << tempVar3;
	
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
}

//--------------------------------------------------------------
void testApp::exit(){
	
	defXML.getSettings();
	
}