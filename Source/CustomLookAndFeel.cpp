#include "CustomLookAndFeel.h"

void CustomLookAndFeel::drawRotarySlider (juce::Graphics & g,
                                          int x,
                                          int y,
                                          int width,
                                          int height,
                                          float sliderPos,
                                          float rotaryStartAngle,
                                          float rotaryEndAngle,
                                          juce::Slider & slider)
{
    auto image_position_index = static_cast<int> (
        std::floor (juce::jmap (sliderPos,
                                0.0f,
                                1.0f,
                                0.0f,
                                static_cast<float> (kNumSliderStages) - 1.0f)));

    auto dial_image_sheet {juce::ImageCache::getFromMemory(BinaryData::dial_image_sheet_jpg, BinaryData::dial_image_sheet_jpgSize)};
    
    auto single_image_width = dial_image_sheet.getWidth();
    auto single_image_height = floor(float(dial_image_sheet.getHeight()) / float(kNumSliderStages));
    
    g.drawImage (dial_image_sheet,
                 x,
                 y,
                 width,
                 height,
                 0.0f,
                 single_image_height * image_position_index,
                 single_image_width,
                 single_image_height);
}
