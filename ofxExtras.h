#pragma once

#include "ofMain.h"
#include "ofAppGlutWindow.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include "Poco/Path.h"
#include "Poco/URI.h"
#include "Poco/Exception.h"
#include "Poco/URIStreamOpener.h"
#include "Poco/Net/HTTPStreamFactory.h"
#include "Poco/Net/HTTPBasicCredentials.h"

#define TAU TWO_PI

#define ofxPrintln(str) cout << str << endl;
#define foreach(t,v) for(typeof(v.begin()) p=v.begin(); p!=v.end(); p++) { typeof(*p) &t=*p; 
#define endfor }

#define ofxBeginApp() class ofApp : public ofBaseApp { public: 
#define ofxEndApp() }; int main() { ofSetupOpenGL(new ofAppGlutWindow,500,500,OF_WINDOW); ofRunApp(new ofApp); }

enum ofxAlign { LEFT, CENTER, RIGHT };
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

ofQuaternion ofxToQuaternion(float lat, float lon);
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
vector<string> ofxLoadStrings(string url);
//vector<string> ofxLoadStrings(string url, string username, string password);
void ofxSaveString(string filename, string str);
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
string ofxReplaceString(string input, string replace, string by);
string ofxFormatDateTime(time_t rawtime, string format);
time_t ofxParseDateTime(string datetime, string format);
time_t ofxGetDateTime();
//vector<string> ofxParseString(string str, string format);

///template<typename T> T ofxFromList(vector<T> &list, float normIndex);
template<typename T> T ofxFromList(vector<T> &list, float normIndex) {
    int index = ofClamp(normIndex * list.size(), 0,list.size()-1);
    if (list.size()==0) return T();
    return list[index];
}

bool ofxStringEndsWith(string str, string key);
bool ofxStringStartsWith(string str, string key);
void ofxScale(float scale);
void ofxNotice(string msg);
void ofxSetHexColor(int hexColor, int a=255);
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
void ofxRotate(ofNode &node, ofQuaternion q);
void ofxTranslate(ofVec3f v);
void ofxScale(ofVec3f v);

void ofxQuadricSphere(float radius, int resolution=32);
void ofxQuadricDisk(float innerRadius, float outerRadius, int resolution=32);
void ofxDrawDisk(ofBaseHasTexture &img,float r, float slices=24);
void ofxDrawSphere(float radius, int segments=32);
void ofxArcStrip(float innerRadius, float outerRadius, float startAngle, float stopAngle); //radians
void ofxArc(float radius, float startAngle, float stopAngle, int detail=32); //radians

void ofxEnableDepthTest();
void ofxDisableDepthTest();

string ofxGetSerialString(ofSerial &serial, char until); //no default because it's confusing
bool ofxGetSerialString(ofSerial &serial, string &output_str, char until);
void ofxSerialWrite(ofSerial &serial, string str);
void ofxSerialWriteLine(ofSerial &serial, string str);

void ofxSetWindowRect(ofRectangle w);

ofVec3f ofxMouseToSphere(float x, float y); //-0.5 ... 0.5
ofVec3f ofxMouseToSphere(ofVec2f v); //-0.5 ... 0.5

bool ofxMouseMoved(); //this one should be fixed to update prev only once per update/draw not per call
ofPoint ofxLerp(ofPoint start, ofPoint end, float amt);
float ofxLerp(float start, float end, float amt);

void ofxSetCursor(bool bVisible);
ofPoint ofxGetCenter();
ofPoint ofxGetMouseFromCenter();

float ofxGetHeading(ofPoint p, ofPoint anchor=ofPoint(0,0)); //radians
ofPoint ofxGetPointOnCircle(float angle, float radius); //radians

int ofxIndex(float x, float y, float w);
void ofxQuadWarp(ofBaseHasTexture &tex, ofPoint lt, ofPoint rt, ofPoint rb, ofPoint lb, int rows=10, int cols=10);
void ofxResetTransform(ofNode &n);

void ofxAssert(bool condition, string message);
string ofxUrlToSafeLocalPath(string url);
string ofxGetFilenameFromUrl(string url);

ofPoint ofxGetCenterOfMass(vector<ofPoint*> points);
ofRectangle ofxGetBoundingBox(vector<ofPoint*> points);
void ofxSimplifyPath(ofPath &path, int iterations=10, float amount=15);
vector<ofPoint*> ofxGetPointsFromPath(ofPath &path);

ofVec3f ofxToCartesian(float lat, float lon);
ofVec3f ofxToCartesian(ofQuaternion q);
void ofxDrawVertex(ofVec3f v);

int ofxGetMultiByteStringLength(); //returns the actual string length instead of the number of chars/bytes

typedef struct { float lat; float lon; } ofxLatLon;

ofxLatLon ofxToLatLon(ofQuaternion q);

string ofxWordWrap(string input, int maxWidth, ofTrueTypeFont *font=0);
