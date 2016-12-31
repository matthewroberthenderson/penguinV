#pragma once

#include <vector>
#include "image_buffer.h"

namespace Image_Function
{
	using namespace Bitmap_Image;

	template <typename TImage>
	uint8_t CommonColorCount(const TImage & image1, const TImage & image2)
	{
		if( image1.colorCount() != image2.colorCount() )
			throw imageException("Color counts of images are different");

		return image1.colorCount();
	}

	template <typename TImage>
	uint8_t CommonColorCount(const TImage & image1, const TImage & image2, const TImage & image3)
	{
		if( image1.colorCount() != image2.colorCount() || image1.colorCount() != image3.colorCount() )
			throw imageException("Color counts of images are different");

		return image1.colorCount();
	}

	template <typename TImage>
	bool IsCorrectColorCount(const TImage & image)
	{
		return image.colorCount() == GRAY_SCALE || image.colorCount() == RGB;
	}

	template <typename TImage>
	void VerifyColoredImage(const TImage & image1)
	{
		if( image1.colorCount() != RGB )
			throw imageException("Bad input parameters in image function: colored image has different than 3 color channels");
	}

	template <typename TImage>
	void VerifyColoredImage(const TImage & image1, const TImage & image2)
	{
		if( image1.colorCount() != RGB || image2.colorCount() != RGB )
			throw imageException("Bad input parameters in image function: colored image has different than 3 color channels");
	}
	
	template <typename TImage>
	void VerifyColoredImage(const TImage & image1, const TImage & image2, const TImage & image3)
	{
		if( image1.colorCount() != RGB || image2.colorCount() != RGB || image3.colorCount() != RGB )
			throw imageException("Bad input parameters in image function: colored image has different than 3 color channels");
	}

	template <typename TImage>
	void VerifyGrayScaleImage(const TImage & image1)
	{
		if( image1.colorCount() != GRAY_SCALE )
			throw imageException("Bad input parameters in image function: gray-scaled image has more than 1 color channels");
	}

	template <typename TImage>
	void VerifyGrayScaleImage(const TImage & image1, const TImage & image2)
	{
		if( image1.colorCount() != GRAY_SCALE || image2.colorCount() != GRAY_SCALE )
			throw imageException("Bad input parameters in image function: gray-scaled image has more than 1 color channels");
	}

	template <typename TImage>
	void VerifyGrayScaleImage(const TImage & image1, const TImage & image2, const TImage & image3)
	{
		if( image1.colorCount() != GRAY_SCALE || image2.colorCount() != GRAY_SCALE || image3.colorCount() != GRAY_SCALE )
			throw imageException("Bad input parameters in image function: gray-scaled image has more than 1 color channels");
	}

	template <typename TImage>
	void ParameterValidation( const TImage & image1 )
	{
		if( image1.empty() || !IsCorrectColorCount(image1) )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TImage>
	void ParameterValidation( const TImage & image1, const TImage & image2 )
	{
		if( image1.empty() || image2.empty() || !IsCorrectColorCount(image1) || !IsCorrectColorCount(image2) ||
			image1.width() != image2.width() || image1.height() != image2.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TImage>
	void ParameterValidation( const TImage & image1, const TImage & image2, const TImage & image3 )
	{
		if( image1.empty() || image2.empty() || image3.empty() || !IsCorrectColorCount(image1) || !IsCorrectColorCount(image2) ||
			!IsCorrectColorCount(image3) || image1.width() != image2.width() || image1.height() != image2.height() ||
			image1.width() != image3.width() || image1.height() != image3.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TImage>
	void ParameterValidation( const TImage & image, uint32_t startX, uint32_t startY, uint32_t width, uint32_t height )
	{
		if( image.empty() || !IsCorrectColorCount(image) || width == 0 || height == 0 || startX + width > image.width() || startY + height > image.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TImage>
	void ParameterValidation( const TImage & image1, uint32_t startX1, uint32_t startY1,
							  const TImage & image2, uint32_t startX2, uint32_t startY2,
							  uint32_t width, uint32_t height )
	{
		if( image1.empty() || image2.empty() || !IsCorrectColorCount(image1) || !IsCorrectColorCount(image2) || width == 0 || height == 0 ||
			startX1 + width > image1.width() || startY1 + height > image1.height() ||
			startX2 + width > image2.width() || startY2 + height > image2.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TImage>
	void ParameterValidation( const TImage & image1, uint32_t startX1, uint32_t startY1,
							  const TImage & image2, uint32_t startX2, uint32_t startY2,
							  const TImage & image3, uint32_t startX3, uint32_t startY3,
							  uint32_t width, uint32_t height )
	{
		if( image1.empty() || image2.empty() || image3.empty() || !IsCorrectColorCount(image1) || !IsCorrectColorCount(image2) ||
			!IsCorrectColorCount(image3) || width == 0 || height == 0 ||
			startX1 + width > image1.width() || startY1 + height > image1.height() ||
			startX2 + width > image2.width() || startY2 + height > image2.height() ||
			startX3 + width > image3.width() || startY3 + height > image3.height() )
			throw imageException("Bad input parameters in image function");
	}

	Image AbsoluteDifference( const Image & in1, const Image & in2 );
	void  AbsoluteDifference( const Image & in1, const Image & in2, Image & out );
	Image AbsoluteDifference( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
							  uint32_t width, uint32_t height );
	void  AbsoluteDifference( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
							  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	void Accumulate( const Image & image, std::vector < uint32_t > & result );
	void Accumulate( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, std::vector < uint32_t > & result );

	Image BitwiseAnd( const Image & in1, const Image & in2 );
	void  BitwiseAnd( const Image & in1, const Image & in2, Image & out );
	Image BitwiseAnd( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  uint32_t width, uint32_t height );
	void  BitwiseAnd( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	Image BitwiseOr( const Image & in1, const Image & in2 );
	void  BitwiseOr( const Image & in1, const Image & in2, Image & out );
	Image BitwiseOr( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					 uint32_t width, uint32_t height );
	void  BitwiseOr( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					 Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	Image BitwiseXor( const Image & in1, const Image & in2 );
	void  BitwiseXor( const Image & in1, const Image & in2, Image & out );
	Image BitwiseXor( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  uint32_t width, uint32_t height );
	void  BitwiseXor( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	Image ConvertToGrayScale( const Image & in );
	void  ConvertToGrayScale( const Image & in, Image & out );
	void  ConvertToGrayScale( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
							 uint32_t width, uint32_t height );

	Image ConvertToRgb( const Image & in );
	void  ConvertToRgb( const Image & in, Image & out );
	void  ConvertToRgb( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					   uint32_t width, uint32_t height );

	void  Copy( const Image & in, Image & out );
	Image Copy( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  Copy( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				uint32_t width, uint32_t height );

	Image ExtractChannel( const Image & in, uint8_t channelId );
	Image ExtractChannel( const Image & in, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint8_t channelId );
	void  ExtractChannel( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut,
						  uint32_t startYOut, uint32_t width, uint32_t height, uint8_t channelId );

	void Fill( Image & image, uint8_t value );
	void Fill( Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, uint8_t value );

	// Make sure that input parameters such as input and output images are not same image!
	// horizontal flip: left-right --> right-left
	// vertical flip: top-bottom --> bottom-top
	Image Flip( const Image & in, bool horizontal, bool vertical );
	void  Flip( const Image & in, Image & out, bool horizontal, bool vertical );
	Image Flip( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height,
				bool horizontal, bool vertical);
	void  Flip( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				uint32_t width, uint32_t height, bool horizontal, bool vertical );

	// Gamma correction works by formula:
	// output = A * ((input / 255) ^ gamma) * 255, where A - multiplication, gamma - power base. Both values must be greater than 0
	// Usually people set A as 1
	Image GammaCorrection( const Image & in, double a, double gamma );
	void  GammaCorrection( const Image & in, Image & out, double a, double gamma );
	Image GammaCorrection( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height, double a, double gamma );
	void  GammaCorrection( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
						   uint32_t width, uint32_t height, double a, double gamma );

	uint8_t GetPixel( const Image & image, uint32_t x, uint32_t y );

	uint8_t GetThreshold( const std::vector < uint32_t > & histogram );

	std::vector < uint32_t > Histogram( const Image & image );
	void                     Histogram( const Image & image, std::vector < uint32_t > & histogram );
	std::vector < uint32_t > Histogram( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height );
	void                     Histogram( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height,
										std::vector < uint32_t > & histogram );

	// Invert function is Bitwise NOT operation. But to make function name more user-friendly we named it like this
	Image Invert( const Image & in );
	void  Invert( const Image & in, Image & out );
	Image Invert( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  Invert( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				  uint32_t width, uint32_t height );

	bool IsEqual( const Image & in1, const Image & in2 );
	bool IsEqual( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				  uint32_t width, uint32_t height );

	Image LookupTable( const Image & in, const std::vector < uint8_t > & table );
	void  LookupTable( const Image & in, Image & out, const std::vector < uint8_t > & table );
	Image LookupTable( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height,
					   const std::vector < uint8_t > & table );
	void  LookupTable( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					   uint32_t width, uint32_t height, const std::vector < uint8_t > & table );

	Image Maximum( const Image & in1, const Image & in2 );
	void  Maximum( const Image & in1, const Image & in2, Image & out );
	Image Maximum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   uint32_t width, uint32_t height );
	void  Maximum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	void Merge( const Image & in1, const Image & in2, const Image & in3, Image & out );
	void Merge( const Image & in1, uint32_t startXIn1, uint32_t startYIn1, const Image & in2, uint32_t startXIn2, uint32_t startYIn2,
				const Image & in3, uint32_t startXIn3, uint32_t startYIn3,  Image & out, uint32_t startXOut, uint32_t startYOut,
				uint32_t width, uint32_t height);

	Image Minimum( const Image & in1, const Image & in2 );
	void  Minimum( const Image & in1, const Image & in2, Image & out );
	Image Minimum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   uint32_t width, uint32_t height );
	void  Minimum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	Image Normalize( const Image & in );
	void  Normalize( const Image & in, Image & out );
	Image Normalize( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  Normalize( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					 uint32_t width, uint32_t height );

	std::vector < uint32_t > ProjectionProfile( const Image & image, bool horizontal );
	void                     ProjectionProfile( const Image & image, bool horizontal, std::vector < uint32_t > & projection );
	std::vector < uint32_t > ProjectionProfile( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, bool horizontal );
	void                     ProjectionProfile( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, bool horizontal,
												std::vector < uint32_t > & projection );

	// Image resizing (scaling) is based on nearest-neighbour interpolation method
	Image Resize( const Image & in, uint32_t widthOut, uint32_t heightOut );
	void  Resize( const Image & in, Image & out );
	Image Resize( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t widthIn, uint32_t heightIn,
				  uint32_t widthOut, uint32_t heightOut );
	void  Resize( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t widthIn, uint32_t heightIn,
				  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t widthOut, uint32_t heightOut );

	Image RgbToBgr( const Image & in );
	void  RgbToBgr( const Image & in, Image & out );
	Image RgbToBgr( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  RgbToBgr( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					uint32_t width, uint32_t height );

	void Rotate( const Image & in, double centerXIn, double centerYIn, Image & out, double centerXOut, double centerYOut, double angle );

	void SetPixel( Image & image, uint32_t x, uint32_t y, uint8_t value );
	void SetPixel( Image & image, const std::vector < uint32_t > & X, const std::vector < uint32_t > & Y, uint8_t value );

	void Split( const Image & in, Image & out1, Image & out2, Image & out3 );
	void Split( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out1, uint32_t startXOut1, uint32_t startYOut1,
				Image & out2, uint32_t startXOut2, uint32_t startYOut2, Image & out3, uint32_t startXOut3, uint32_t startYOut3,
				uint32_t width, uint32_t height);

	Image Subtract( const Image & in1, const Image & in2 );
	void  Subtract( const Image & in1, const Image & in2, Image & out );
	Image Subtract( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					uint32_t width, uint32_t height );
	void  Subtract( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	// Make sure that your image is not so big to do not have overloaded uint32_t value
	// For example not bigger than [4096 * 4096] for 32-bit application
	uint32_t Sum( const Image & image );
	uint32_t Sum( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height );

	// Thresholding works in such way:
		// if pixel intensity on input image is          less (  < ) than threshold then set pixel intensity on output image as 0
		// if pixel intensity on input image is equal or more ( >= ) than threshold then set pixel intensity on output image as 255
	Image Threshold( const Image & in, uint8_t threshold );
	void  Threshold( const Image & in, Image & out, uint8_t threshold );
	Image Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height, uint8_t threshold );
	void  Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					 uint32_t width, uint32_t height, uint8_t threshold );

	// Thresholding works in such way:
		// if pixel intensity on input image is less ( < ) than minimum threshold or more ( > ) than maximum threshold
		// then      set pixel intensity on output image as 0
		// otherwise set pixel intensity on output image as 255
	Image Threshold( const Image & in, uint8_t minThreshold, uint8_t maxThreshold );
	void  Threshold( const Image & in, Image & out, uint8_t minThreshold, uint8_t maxThreshold );
	Image Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height, uint8_t minThreshold,
					 uint8_t maxThreshold );
	void  Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					 uint32_t width, uint32_t height, uint8_t minThreshold, uint8_t maxThreshold );

	// Swap columns and rows in input image. It is equivalent to 90 degree rotation
	// Output image (area) must be [height, width] compare to original [width, height]
	Image Transpose( const Image & in );
	void  Transpose( const Image & in, Image & out );
	Image Transpose( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  Transpose( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					 uint32_t width, uint32_t height );
};
