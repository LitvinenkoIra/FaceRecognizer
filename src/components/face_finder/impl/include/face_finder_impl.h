#ifndef SCR_COMPONENTS_FACE_FINDER_INCLUDE_FACE_FINDER_IMPL_H
#define SCR_COMPONENTS_FACE_FINDER_INCLUDE_FACE_FINDER_IMPL_H

#include <opencv2/objdetect/objdetect.hpp>
#include "face_finder/face_finder.h"
#include "config/config.h"

namespace face_finder {

class FaceFinderImpl : public FaceFinder {
 public:
    FaceFinderImpl(const config::Config& config);
    Faces FindFaces(const cv::Mat& frame) override;
 private:
    cv::CascadeClassifier face_cascade_;
    const config::Config& config_;
    double scale_factor_;
    int min_neighbors_;
    cv::Size min_size_;
    cv::Size max_size_;

};

}  //  namespace face_finder
#endif  // SCR_COMPONENTS_FACE_FINDER_INCLUDE_FACE_FINDER_IMPL_H
