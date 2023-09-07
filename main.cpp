#include<llh_converter/llh_converter.hpp>

#include<iomanip>
#include<iostream>

#include<stdlib.h>

void usage(char* name){
	std::cout << "Usage: " << name << " x y grid" << std::endl;
}

int main(int argc, char** argv){
	if(argc <= 3){
		usage(argv[0]);
		return 1;
	}

	double x = atof(argv[1]);
	double y = atof(argv[2]);

	llh_converter::LLHParam param;  // parameter for conversion
	param.use_mgrs = true;          // set true if you want to use MGRS
	param.plane_num = 9;            // set the plane number when you use JPRCS
	param.mgrs_code = argv[3];      // MGRS grid code is required when you revert MGRS x/y into lat/lon
	param.height_convert_type = llh_converter::ConvertType::ELLIPS2ORTHO;
	                                // You can also convert height
	param.geoid_type = llh_converter::GeoidType::EGM2008;
	                                // Set geoid model
	
	double lat, lon;
	llh_converter::LLHConverter lc;
	lc.revertXYZ2Deg(x, y, lat, lon, param);
	std::cout << std::fixed << std::setprecision(8) << lat << "," \
		  << std::fixed << std::setprecision(8) << lon << std::endl;

	return 0;
}
