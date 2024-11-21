#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetLineWidth(3);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(1000);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofColor color;
	auto noise_p = ofRandom(1000);
	for (int hue = 0; hue < 255; hue += 32) {

		noise_p += 0.2;
		auto deg_start = ofMap(hue, 0, 255, 0, 360);

		color.setHsb(hue, 200, 255);
		
		ofSetColor(ofColor(color, 92));
		ofFill();
		
		ofBeginShape();
		for (int deg = deg_start; deg < deg_start + 360; deg += 1) {

			auto noise_location = glm::vec4(noise_p, cos(deg * DEG_TO_RAD) * 0.15, sin(deg * DEG_TO_RAD) * 0.15, ofGetFrameNum() * 0.015);
			auto radius = ofMap(ofNoise(noise_location), 0, 1, 50, 360);

			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			ofVertex(location);
		}

		ofNextContour(true);

		for (int deg = deg_start; deg < deg_start + 360; deg += 1) {

			auto noise_location = glm::vec4(noise_p, cos(deg * DEG_TO_RAD) * 0.15, sin(deg * DEG_TO_RAD) * 0.15, ofGetFrameNum() * 0.015);
			auto radius = ofMap(ofNoise(noise_location), 0, 1, 50, 360) - 15;

			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			ofVertex(location);
		}

		ofEndShape(true);

		ofSetColor(ofColor(color));
		ofNoFill();

		ofBeginShape();
		for (int deg = deg_start; deg < deg_start + 360; deg += 1) {

			auto noise_location = glm::vec4(noise_p, cos(deg * DEG_TO_RAD) * 0.15, sin(deg * DEG_TO_RAD) * 0.15, ofGetFrameNum() * 0.015);
			auto radius = ofMap(ofNoise(noise_location), 0, 1, 50, 360);

			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			ofVertex(location);
		}
		ofEndShape(true);

		ofBeginShape();
		for (int deg = deg_start; deg < deg_start + 360; deg += 1) {

			auto noise_location = glm::vec4(noise_p, cos(deg * DEG_TO_RAD) * 0.15, sin(deg * DEG_TO_RAD) * 0.15, ofGetFrameNum() * 0.015);
			auto radius = ofMap(ofNoise(noise_location), 0, 1, 50, 360) - 15;

			auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			ofVertex(location);
		}
		ofEndShape(true);
	}

	/*
	int start = 75;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}