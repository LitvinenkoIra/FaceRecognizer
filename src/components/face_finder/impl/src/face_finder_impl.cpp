#include "face_finder_impl.h"
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>


namespace face_finder {

const std::string kSectionName = "FaceFinder";
const std::string kScaleFactor = "ScaleFactor";
const std::string kMinNeighbors = "MinNeighbors";
const std::string kMinSize = "MinSize";
const std::string kMaxSize = "MaxSize";

FaceFinderImpl::FaceFinderImpl(const config::Config& config):
    config_(config), scale_factor_(config.GetDoubleValue(kSectionName, kScaleFactor)){
    assert(face_cascade_.load("haarcascade_frontalface_alt.xml"));
}

Faces FaceFinderImpl::FindFaces(const cv::Mat& frame) {
    Faces faces;
    cv::Mat frame_gray;
    cv::cvtColor( frame, frame_gray, CV_BGR2GRAY );
    cv::equalizeHist( frame_gray, frame_gray );
    face_cascade_.detectMultiScale( frame_gray, faces,
    scale_factor_, min_neighbors_, 0|CV_HAAR_SCALE_IMAGE, min_size_, max_size_);
    return faces;
}



}  // namespace face_finder
