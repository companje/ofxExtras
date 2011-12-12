#ifndef OFX_EXTRAS
#define OFX_EXTRAS

#include "ofMain.h"
#include <fstream> //for ofxFileExists

#define OFX_ALIGN_LEFT 0
#define OFX_ALIGN_CENTER 1
#define OFX_ALIGN_RIGHT 2

int ofxToInteger(string str);
bool ofxToBoolean(string sValue);
bool ofxToBoolean(float f);
ofMatrix4x4 ofxToMatrix4x4(string str);
string ofxToString(int value);
string ofxToString(bool value);
string ofxToString(ofRectangle value);
string ofxToString(string str);
string ofxToString(char ch);
string ofxToString(unsigned char ch);
string ofxToString(float f);
string ofxToString(ofQuaternion q);
string ofxToString(ofColor c);
string ofxToHexString(int value, int digits);

ofQuaternion ofxToQuaternion(string str);
ofRectangle ofxToRectangle(string str);
vector<string> ofxToStringVector(string value);
int ofxToInteger(ofColor c);
ofColor ofxToColor(unsigned char r, unsigned char g, unsigned char b);
ofColor ofxToColor(string hex);
ofColor ofxToColor(int hexColor);
void ofxSetTexture(ofBaseHasTexture &material);
void ofxSetTexture(ofTexture &texture);
void ofxDisableTexture();
bool ofxFileExists(string filename);
string ofxGetFileExtension(string filename);
string ofxAddTrailingSlash(string foldername);
string ofxAddTrailingString(string str, string trail);
vector<string> ofxLoadStrings(string filename);
void ofxSaveStrings(string filename, vector<string> lines);
vector<string> ofxReadFiles(string folder);
string ofxGetHostName();
void ofxExit(string msg);
void ofxExit();
string ofxTrimString(string str);
string ofxTrimStringLeft(string str);
string ofxTrimStringRight(string str);
string ofxStringBeforeFirst(string str, string key);
string ofxStringAfterFirst(string str, string key);
string ofxFormatString(string format, int number);
string ofxFormatString(string format, string s);
string ofxFromList(vector<string> &list, float normIndex);
bool ofxStringEndsWith(string str, string key);
bool ofxStringStartsWith(string str, string key);
void ofxScale(float scale);
void ofxNotice(string msg);
void ofxSetColor(int hexColor, int a=255);
void ofxSetColor(ofColor c);
void ofxSetColorHSB(int h, int s, int b, int a=255);
float ofxDist(float x1, float y1, float z1, float x2, float y2, float z2);
bool ofxColorMatch(ofColor a, ofColor b, int tolerance=0);

string ofxToString(ofMatrix4x4 m);
string ofxToString(ofVec2f value);
string ofxToString(ofVec3f v, int precision=7);
string ofxToString(ofVec4f value);
ofVec2f ofxToVec2f(string str);
ofVec3f ofxToVec3f(string str);
ofVec3f ofxToVec3f(float *a);
ofVec4f ofxToVec4f(string str);
ofRectangle ofxToRectangle(ofVec4f v);
void ofxRotate(float angle, ofVec3f v);
void ofxRotate(ofVec3f v);
void ofxRotate(ofQuaternion q);
void ofxTranslate(ofVec3f v);
void ofxScale(ofVec3f v);

void ofxQuadricSphere(float radius, int resolution=32);
void ofxQuadricDisk(float innerRadius, float outerRadius, int resolution=32);
void ofxEnableDepthTest();
void ofxDisableDepthTest();

string ofxGetSerialString(ofSerial &serial, char until='\0');
void ofxSetWindowRect(ofRectangle w);

ofVec3f ofxMouseToSphere(float x, float y); //-0.5 ... 0.5
ofVec3f ofxMouseToSphere(ofVec2f v); //-0.5 ... 0.5

bool ofxMouseMoved();
void ofxSetCursor(bool bVisible);

float ofxGetHeading2D(ofVec2f v);

#endif
