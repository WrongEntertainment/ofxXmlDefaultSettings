/**
 *  ofxXmlDefaultSettings.h
 *
 *  
 *  The MIT License
 *
 *  Copyright (c) 2012 Paul Vollmer, http://www.wng.cc
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
 *  @dependencies       ofxXmlSettings
 *  @modified           2012.05.15
 *  @version            0.1.0e
 */

#include "ofxXmlSettings.h"

// If "OFXXMLDEFAULTSETTINGS_LOG" is defined, the addon prints out ofLog messages.
//#define OFXXMLDEFAULTSETTINGS_LOG





/**
 * This is our base class.
 * with this class we create a default xml file with default content.
 * From this defaul file we grab our setting values.
 */
class ofxXmlDefaultSettings : public ofxXmlSettings {
	
	public:
		ofxXmlDefaultSettings();
		
		
		void load(string filepath);
		void load();
	
		bool saveSettings();
	
		void setSettings();
		void setFrameRate();
		void setWindowShape();
		void setWindowPosition();
		void setWindowTitle();
		void setCursor();
		void setFullscreen();
		void setEscapeQuitsApp();
		void setLogToFile();
		
		string filepath;
	
	
	private:
		void createDefaultXml();
		
};





/**
 * This is our ofxOsc addon settigs class.
 * We can init, get and set values.
 */
class ofxXmlOscSettings : public ofxXmlDefaultSettings {
	
	public:
		ofxXmlOscSettings();
	
		void initSender(ofxXmlDefaultSettings XML, string host, int port);
		void initSender(ofxXmlDefaultSettings XML);
	
		string getSenderHost(ofxXmlDefaultSettings XML);
		int getSenderPort(ofxXmlDefaultSettings XML);
	
		void setSenderHost(ofxXmlDefaultSettings XML, string h);
		void setSenderPort(ofxXmlDefaultSettings XML, int p);
	
};
