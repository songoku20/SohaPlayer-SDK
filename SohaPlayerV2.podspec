#
# Be sure to run `pod lib lint SohaPlayerV2.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#
e
Pod::Spec.new do |s|
  s.name             = 'SohaPlayerV2'
  s.version          = '1.3.5-pro'
  s.summary          = 'Everything about this project under our ownership'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = "Everything about this project under our ownership, giong cai sumary no chui"

  s.homepage         = 'https://github.com/songoku20/SohaPlayer-SDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = 'MIT'
  s.author           = { 'songoku20' => 'sonleminh@vccorp.vn' }
  # s.source           = { :git => 'https://github.com/songoku20/SohaPlayerV2.git', :tag => s.version.to_s }
  s.source           = { :http => "https://github.com/songoku20/SohaPlayer-SDK/releases/download/1.3.5-pro/SohaPlayerV2-1.3.5-pro.zip" }

  # s.ios.deployment_target = '8.0'
  s.source_files = 'SohaPlayerV2/Classes/**/*'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64 x86_64' }
  s.frameworks          = ["SystemConfiguration", "QuartzCore", "CoreMedia", "AVFoundation", "AudioToolbox", "AdSupport", "ImageIO", "WebKit", "Social", "MediaAccessibility"]
  s.library             = "z", "System", "xml2", "xml2.2", "c++"
  s.requires_arc        = true
  
  s.platform            = :ios, '8.0'
  s.preserve_paths      = 'SohaPlayer.framework'
  s.public_header_files = 'SohaPlayer.framework/Versions/A/Headers/SohaPlayerManager.h'
  s.source_files        = 'SohaPlayer.framework/Versions/A/Headers/SohaPlayerManager.h'
  s.resource            = 'SohaPlayer.bundle'
  s.vendored_frameworks = 'SohaPlayer.framework'
  # s.vendored_library    = 'libstdc++.6.0.9.dylib', 'libstdc++.6.dylib'
  s.dependency 'SecureSDK', '>= 0.1.3'
  #s.dependency 'SHLogging'
end