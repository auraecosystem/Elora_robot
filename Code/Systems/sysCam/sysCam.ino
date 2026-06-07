#include <Camera.h>

//==================================================================================================
// Configuration
//==================================================================================================

constexpr unsigned long CAMERA_READ_INTERVAL = 10;
constexpr bool DEBUG = true;

//==================================================================================================
// Camera Objects
//==================================================================================================

Camera cam_l;
Camera cam_r;

//==================================================================================================
// Timing
//==================================================================================================

unsigned long lastCameraRead = 0;

//==================================================================================================
// Helper Functions
//==================================================================================================

void processCamera(Camera* camera, const char* cameraName) {
    int blob = camLineBlobFilter(camera);
    int cell = camDefineCell(blob);

    Serial.print(cameraName);
    Serial.print(" Defined Cell: ");
    Serial.println(cell);
}

//==================================================================================================
// Setup
//==================================================================================================

void setup() {
    Serial.begin(115200);

    camSetup();

    if (DEBUG) {
        Serial.println("Camera system initialized");
    }
}

//==================================================================================================
// Main Loop
//==================================================================================================

void loop() {
    unsigned long now = millis();

    if (now - lastCameraRead >= CAMERA_READ_INTERVAL) {

        // Read all cameras
        camRead();

        // Process left camera
        processCamera(&cam_l, "LEFT");

        // Process right camera
        processCamera(&cam_r, "RIGHT");

        // Optional debugging
        if (DEBUG) {
            // debugCameraL();
            // debugCameraR();
        }

        lastCameraRead = now;
    }
}
