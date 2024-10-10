
camera {
	location <-680,110,564>
	look_at <0,0,0>
	angle 20
	right x*image_width/image_height
	 }

light_source {
	<-1000,500,500>
	rgb <1,1,1>
	shadowless
	}
light_source {
	<100,0,300>
	rgb <1,1,1>
	shadowless
	}


background {
	color rgb <1,	1,	1>	}

background { color rgb <1.0, 1.0, 1.0> }
difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<102.139,0,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,106.364>
	 translate <102.139,0,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-106.364>
	 translate <102.139,0,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.1794>
	 rotate <0,164.007,0>
	 rotate <0,0,0>
	 translate <102.139,0,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,39.9895>
	 rotate <0,132.64,0>
	 rotate <0,0,90.23>
	 translate <102.139,0,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,39.9895>
	 rotate <0,132.64,0>
	 rotate <0,0,-90.23>
	 translate <102.139,0,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,74.0067,0>
	 rotate <0,0,0>
	 translate <111.991,0,32.0986>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-16.3636>
	 translate <95.9428,-28.1714,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,16.3636>
	 translate <95.9428,28.1714,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<85.9249,55.2206,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-73.6364>
	 translate <85.9249,55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,139.091>
	 translate <85.9249,55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,41.8093>
	 rotate <0,130.384,0>
	 rotate <0,0,-60.1084>
	 translate <85.9249,55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.2999>
	 rotate <0,163.176,0>
	 rotate <0,0,12.742>
	 translate <85.9249,55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,38.2373>
	 rotate <0,135.108,0>
	 rotate <0,0,120.128>
	 translate <85.9249,55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,49.0909>
	 translate <65.4817,75.5699,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,16.3636>
	 translate <95.9428,28.1714,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,74.0024,0>
	 rotate <0,0,31.2673>
	 translate <95.7226,58.1254,32.107>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<42.4301,92.909,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-40.9091>
	 translate <42.4301,92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,171.818>
	 translate <42.4301,92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,43.6845>
	 rotate <0,128.323,0>
	 rotate <0,0,-29.8108>
	 translate <42.4301,92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.6582>
	 rotate <0,160.95,0>
	 rotate <0,0,28.7355>
	 translate <42.4301,92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.5667>
	 rotate <0,137.8,0>
	 rotate <0,0,149.736>
	 translate <42.4301,92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,49.0909>
	 translate <65.4817,75.5699,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9896,0>
	 rotate <0,0,62.5345>
	 translate <51.6474,99.3596,32.1321>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,81.8182>
	 translate <14.2305,98.9755,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-14.5359,101.099,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-8.18182>
	 translate <-14.5359,101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-155.455>
	 translate <-14.5359,101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,45.6041>
	 rotate <0,126.441,0>
	 rotate <0,0,0.627398>
	 translate <-14.5359,101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.2446>
	 rotate <0,157.862,0>
	 rotate <0,0,48.7377>
	 translate <-14.5359,101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,34.9933>
	 rotate <0,140.724,0>
	 rotate <0,0,178.961>
	 translate <-14.5359,101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,114.545>
	 translate <-41.5387,90.9571,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,125.068>
	 translate <-64.322,91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,109.871>
	 translate <-38.0127,105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9682,0>
	 rotate <0,0,93.8014>
	 translate <-7.42339,111.723,32.174>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,81.8182>
	 translate <14.2305,98.9755,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-66.8869,77.1916,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,24.5455>
	 translate <-66.8869,77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-122.727>
	 translate <-66.8869,77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,47.5587>
	 rotate <0,124.721,0>
	 rotate <0,0,31.1797>
	 translate <-66.8869,77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.0445>
	 rotate <0,154.372,0>
	 rotate <0,0,71.9497>
	 translate <-66.8869,77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,33.5348>
	 rotate <0,143.88,0>
	 rotate <0,0,-152.333>
	 translate <-66.8869,77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,114.545>
	 translate <-41.5387,90.9571,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,141.135>
	 translate <-87.1062,70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,147.273>
	 translate <-84.1197,54.0604,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,125.068>
	 translate <-64.322,91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,109.871>
	 translate <-38.0127,105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,156.334>
	 translate <-102.517,44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-98.0017,28.7759,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,57.2727>
	 translate <-98.0017,28.7759,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-90>
	 translate <-98.0017,28.7759,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.0398>
	 rotate <0,150.775,0>
	 rotate <0,0,97.395>
	 translate <-98.0017,28.7759,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.2102>
	 rotate <0,147.246,0>
	 rotate <0,0,-124.349>
	 translate <-98.0017,28.7759,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,165>
	 translate <-112.446,30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,172.4>
	 translate <-110.92,14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,141.135>
	 translate <-87.1062,70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,147.273>
	 translate <-84.1197,54.0604,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,156.334>
	 translate <-102.517,44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-180>
	 translate <-99.9933,-1.22456e-14,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,-172.4>
	 translate <-110.92,-14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-98.0017,-28.7759,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,90>
	 translate <-98.0017,-28.7759,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-57.2727>
	 translate <-98.0017,-28.7759,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.2102>
	 rotate <0,147.246,0>
	 rotate <0,0,124.349>
	 translate <-98.0017,-28.7759,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.0398>
	 rotate <0,150.775,0>
	 rotate <0,0,-97.395>
	 translate <-98.0017,-28.7759,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,172.4>
	 translate <-110.92,14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-147.273>
	 translate <-84.1197,-54.0604,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-165>
	 translate <-112.446,-30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-180>
	 translate <-99.9933,-1.22456e-14,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,-141.135>
	 translate <-87.1062,-70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,-172.4>
	 translate <-110.92,-14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,-156.334>
	 translate <-102.517,-44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-66.8869,-77.1916,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,122.727>
	 translate <-66.8869,-77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-24.5455>
	 translate <-66.8869,-77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,33.5348>
	 rotate <0,143.88,0>
	 rotate <0,0,152.333>
	 translate <-66.8869,-77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.0445>
	 rotate <0,154.372,0>
	 rotate <0,0,-71.9497>
	 translate <-66.8869,-77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,47.5587>
	 rotate <0,124.721,0>
	 rotate <0,0,-31.1797>
	 translate <-66.8869,-77.1916,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,-109.871>
	 translate <-38.0127,-105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-114.545>
	 translate <-41.5387,-90.9571,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,-125.068>
	 translate <-64.322,-91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-147.273>
	 translate <-84.1197,-54.0604,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,-141.135>
	 translate <-87.1062,-70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,-156.334>
	 translate <-102.517,-44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-14.5359,-101.099,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,155.455>
	 translate <-14.5359,-101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,8.18182>
	 translate <-14.5359,-101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,34.9933>
	 rotate <0,140.724,0>
	 rotate <0,0,-178.961>
	 translate <-14.5359,-101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.2446>
	 rotate <0,157.862,0>
	 rotate <0,0,-48.7377>
	 translate <-14.5359,-101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,45.6041>
	 rotate <0,126.441,0>
	 rotate <0,0,-0.627398>
	 translate <-14.5359,-101.099,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,-109.871>
	 translate <-38.0127,-105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9682,0>
	 rotate <0,0,-93.8014>
	 translate <-7.42339,-111.723,32.174>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-114.545>
	 translate <-41.5387,-90.9571,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-81.8182>
	 translate <14.2305,-98.9755,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,-125.068>
	 translate <-64.322,-91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<42.4301,-92.909,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-171.818>
	 translate <42.4301,-92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,40.9091>
	 translate <42.4301,-92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.5667>
	 rotate <0,137.8,0>
	 rotate <0,0,-149.736>
	 translate <42.4301,-92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.6582>
	 rotate <0,160.95,0>
	 rotate <0,0,-28.7355>
	 translate <42.4301,-92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,43.6845>
	 rotate <0,128.323,0>
	 rotate <0,0,29.8108>
	 translate <42.4301,-92.909,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-49.0909>
	 translate <65.4817,-75.5699,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-81.8182>
	 translate <14.2305,-98.9755,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9896,0>
	 rotate <0,0,-62.5345>
	 translate <51.6474,-99.3596,32.1321>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<85.9249,-55.2206,58.589>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,73.6364>
	 translate <85.9249,-55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.7759>
	 rotate <0,90,0>
	 rotate <0,0,-139.091>
	 translate <85.9249,-55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,41.8093>
	 rotate <0,130.384,0>
	 rotate <0,0,60.1084>
	 translate <85.9249,-55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,38.2373>
	 rotate <0,135.108,0>
	 rotate <0,0,-120.128>
	 translate <85.9249,-55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.2999>
	 rotate <0,163.176,0>
	 rotate <0,0,-12.742>
	 translate <85.9249,-55.2206,58.589>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-16.3636>
	 translate <95.9428,-28.1714,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-49.0909>
	 translate <65.4817,-75.5699,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,74.0024,0>
	 rotate <0,0,-31.2673>
	 translate <95.7226,-58.1254,32.107>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<117.667,0,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.1794>
	 rotate <0,15.9933,0>
	 rotate <0,0,180>
	 translate <117.667,0,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,41.8093>
	 rotate <0,49.6158,0>
	 rotate <0,0,119.892>
	 translate <117.667,0,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,41.8093>
	 rotate <0,49.6158,0>
	 rotate <0,0,-119.892>
	 translate <117.667,0,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,105>
	 translate <117.667,0,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-105>
	 translate <117.667,0,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.1794>
	 rotate <0,168.301,0>
	 rotate <0,0,180>
	 translate <117.667,0,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,42.2648>
	 rotate <0,130.759,0>
	 rotate <0,0,116.224>
	 translate <117.667,0,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,42.2648>
	 rotate <0,130.759,0>
	 rotate <0,0,-116.224>
	 translate <117.667,0,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,74.0067,0>
	 rotate <0,0,0>
	 translate <111.991,0,32.0986>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-15>
	 translate <112.446,-30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<3.3782,0.905185,0.135749>,<114.859,30.7763,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<3.42729,0,-0.709698>,<116.528,0,-24.1297>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<101.903,58.8337,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,39.9895>
	 rotate <0,47.3596,0>
	 rotate <0,0,-89.77>
	 translate <101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.2999>
	 rotate <0,16.8236,0>
	 rotate <0,0,-167.258>
	 translate <101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,43.6845>
	 rotate <0,51.6766,0>
	 rotate <0,0,150.189>
	 translate <101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-75>
	 translate <101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,135>
	 translate <101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,40.3916>
	 rotate <0,133.091,0>
	 rotate <0,0,-85.7845>
	 translate <101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.3048>
	 rotate <0,167.133,0>
	 rotate <0,0,-173.641>
	 translate <101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,44.1935>
	 rotate <0,128.638,0>
	 rotate <0,0,146.799>
	 translate <101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.702,0>
	 rotate <0,0,31.294>
	 translate <97.4816,59.2558,-23.6292>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,74.0024,0>
	 rotate <0,0,31.2673>
	 translate <95.7226,58.1254,32.107>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<3.3782,0.905185,0.135749>,<114.859,30.7763,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<2.47301,2.47301,0.135749>,<84.0824,84.0824,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<58.8337,101.903,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,38.2373>
	 rotate <0,44.8921,0>
	 rotate <0,0,-59.8721>
	 translate <58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.6582>
	 rotate <0,19.0497,0>
	 rotate <0,0,-151.264>
	 translate <58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,45.6041>
	 rotate <0,53.5588,0>
	 rotate <0,0,-179.373>
	 translate <58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-45>
	 translate <58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,165>
	 translate <58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,38.5864>
	 rotate <0,135.653,0>
	 rotate <0,0,-55.5172>
	 translate <58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.6772>
	 rotate <0,164.202,0>
	 rotate <0,0,-160.298>
	 translate <58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,46.1665>
	 rotate <0,126.706,0>
	 rotate <0,0,177.48>
	 translate <58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.712,0>
	 rotate <0,0,62.588>
	 translate <52.5183,101.266,-23.6484>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9896,0>
	 rotate <0,0,62.5345>
	 translate <51.6474,99.3596,32.1321>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,75>
	 translate <30.1297,112.446,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<2.47301,2.47301,0.135749>,<84.0824,84.0824,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<7.20505e-15,117.667,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,36.5667>
	 rotate <0,42.2001,0>
	 rotate <0,0,-30.2639>
	 translate <7.20505e-15,117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.2446>
	 rotate <0,22.1376,0>
	 rotate <0,0,-131.262>
	 translate <7.20505e-15,117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,47.5587>
	 rotate <0,55.2788,0>
	 rotate <0,0,-148.82>
	 translate <7.20505e-15,117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-15>
	 translate <7.20505e-15,117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-165>
	 translate <7.20505e-15,117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.8635>
	 rotate <0,138.465,0>
	 rotate <0,0,-25.4767>
	 translate <7.20505e-15,117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.2865>
	 rotate <0,160.426,0>
	 rotate <0,0,-140.397>
	 translate <7.20505e-15,117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,105>
	 translate <-30.1297,112.446,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,109.871>
	 translate <-38.0127,105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9682,0>
	 rotate <0,0,93.8014>
	 translate <-7.42339,111.723,32.174>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,75>
	 translate <30.1297,112.446,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.728,0>
	 rotate <0,0,93.8818>
	 translate <-7.72213,113.806,-23.6805>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-1.15188,3.22516,-0.722174>,<-39.1641,109.655,-24.5539>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-58.8337,101.903,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,34.9933>
	 rotate <0,39.2755,0>
	 rotate <0,0,-1.03908>
	 translate <-58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.0445>
	 rotate <0,25.6284,0>
	 rotate <0,0,-108.05>
	 translate <-58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,15>
	 translate <-58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-135>
	 translate <-58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,35.2394>
	 rotate <0,141.54,0>
	 rotate <0,0,4.25863>
	 translate <-58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.117>
	 rotate <0,156.381,0>
	 rotate <0,0,-116.421>
	 translate <-58.8337,101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,105>
	 translate <-30.1297,112.446,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.751,0>
	 rotate <0,0,125.175>
	 translate <-65.7069,93.2307,-23.7255>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,141.135>
	 translate <-87.1062,70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,125.068>
	 translate <-64.322,91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,109.871>
	 translate <-38.0127,105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.858,0>
	 rotate <0,0,140.946>
	 translate <-88.538,71.8342,-23.9397>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-1.15188,3.22516,-0.722174>,<-39.1641,109.655,-24.5539>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-2.47301,2.47301,0.135749>,<-84.0824,84.0824,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-101.903,58.8337,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,33.5348>
	 rotate <0,36.1205,0>
	 rotate <0,0,27.6667>
	 translate <-101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.0398>
	 rotate <0,29.2251,0>
	 rotate <0,0,-82.605>
	 translate <-101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,45>
	 translate <-101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-105>
	 translate <-101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,33.732>
	 rotate <0,144.889,0>
	 rotate <0,0,33.5707>
	 translate <-101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.1492>
	 rotate <0,152.358,0>
	 rotate <0,0,-90.0656>
	 translate <-101.903,58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,165>
	 translate <-112.446,30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,172.4>
	 translate <-110.92,14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.751,0>
	 rotate <0,0,125.175>
	 translate <-65.7069,93.2307,-23.7255>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,172.239>
	 translate <-112.987,15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,141.135>
	 translate <-87.1062,70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,156.469>
	 translate <-104.562,45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,125.068>
	 translate <-64.322,91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,156.334>
	 translate <-102.517,44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.858,0>
	 rotate <0,0,140.946>
	 translate <-88.538,71.8342,-23.9397>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-2.47301,2.47301,0.135749>,<-84.0824,84.0824,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-117.667,6.66649e-14,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,32.2102>
	 rotate <0,32.7543,0>
	 rotate <0,0,55.6511>
	 translate <-117.667,6.66649e-14,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.2102>
	 rotate <0,32.7543,0>
	 rotate <0,0,-55.6511>
	 translate <-117.667,6.66649e-14,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,75>
	 translate <-117.667,6.66649e-14,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-75>
	 translate <-117.667,6.66649e-14,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.3615>
	 rotate <0,148.504,0>
	 rotate <0,0,62.2742>
	 translate <-117.667,6.66649e-14,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.3615>
	 rotate <0,148.504,0>
	 rotate <0,0,-62.2742>
	 translate <-117.667,6.66649e-14,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,-172.239>
	 translate <-112.987,-15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,165>
	 translate <-112.446,30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,172.4>
	 translate <-110.92,14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,172.239>
	 translate <-112.987,15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,156.469>
	 translate <-104.562,45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,-156.469>
	 translate <-104.562,-45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,156.334>
	 translate <-102.517,44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-165>
	 translate <-112.446,-30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,-172.4>
	 translate <-110.92,-14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,-156.334>
	 translate <-102.517,-44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-101.903,-58.8337,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,31.0398>
	 rotate <0,29.2251,0>
	 rotate <0,0,82.605>
	 translate <-101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,33.5348>
	 rotate <0,36.1205,0>
	 rotate <0,0,-27.6667>
	 translate <-101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,105>
	 translate <-101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-45>
	 translate <-101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.1492>
	 rotate <0,152.358,0>
	 rotate <0,0,90.0656>
	 translate <-101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,33.732>
	 rotate <0,144.889,0>
	 rotate <0,0,-33.5707>
	 translate <-101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,-172.239>
	 translate <-112.987,-15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,-156.469>
	 translate <-104.562,-45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,-125.068>
	 translate <-64.322,-91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-165>
	 translate <-112.446,-30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,-141.135>
	 translate <-87.1062,-70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,-172.4>
	 translate <-110.92,-14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,-156.334>
	 translate <-102.517,-44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-2.65994,-2.15811,-0.719218>,<-90.438,-73.3757,-24.4534>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-2.47301,-2.47301,0.135749>,<-84.0824,-84.0824,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-58.8337,-101.903,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,30.0445>
	 rotate <0,25.6284,0>
	 rotate <0,0,108.05>
	 translate <-58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,34.9933>
	 rotate <0,39.2755,0>
	 rotate <0,0,1.03908>
	 translate <-58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,135>
	 translate <-58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-15>
	 translate <-58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.117>
	 rotate <0,156.381,0>
	 rotate <0,0,116.421>
	 translate <-58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,35.2394>
	 rotate <0,141.54,0>
	 rotate <0,0,-4.25863>
	 translate <-58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,-109.871>
	 translate <-38.0127,-105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-105>
	 translate <-30.1297,-112.446,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.908,0>
	 rotate <0,0,-109.655>
	 translate <-38.3413,-107.352,-24.0381>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,-125.068>
	 translate <-64.322,-91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,-141.135>
	 translate <-87.1062,-70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-1.97403,-2.80092,-0.712784>,<-67.1169,-95.2313,-24.2347>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-2.65994,-2.15811,-0.719218>,<-90.438,-73.3757,-24.4534>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-2.47301,-2.47301,0.135749>,<-84.0824,-84.0824,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-2.16151e-14,-117.667,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,47.5587>
	 rotate <0,55.2788,0>
	 rotate <0,0,148.82>
	 translate <-2.16151e-14,-117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.2446>
	 rotate <0,22.1376,0>
	 rotate <0,0,131.262>
	 translate <-2.16151e-14,-117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.5667>
	 rotate <0,42.2001,0>
	 rotate <0,0,30.2639>
	 translate <-2.16151e-14,-117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,165>
	 translate <-2.16151e-14,-117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,15>
	 translate <-2.16151e-14,-117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.2865>
	 rotate <0,160.426,0>
	 rotate <0,0,140.397>
	 translate <-2.16151e-14,-117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.8635>
	 rotate <0,138.465,0>
	 rotate <0,0,25.4767>
	 translate <-2.16151e-14,-117.667,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,-109.871>
	 translate <-38.0127,-105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-105>
	 translate <-30.1297,-112.446,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9682,0>
	 rotate <0,0,-93.8014>
	 translate <-7.42339,-111.723,32.174>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.908,0>
	 rotate <0,0,-109.655>
	 translate <-38.3413,-107.352,-24.0381>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<0.905185,-3.3782,0.135749>,<30.7763,-114.859,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-0.231995,-3.41907,-0.711431>,<-7.88784,-116.248,-24.1887>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<58.8337,-101.903,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,45.6041>
	 rotate <0,53.5588,0>
	 rotate <0,0,179.373>
	 translate <58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.6582>
	 rotate <0,19.0497,0>
	 rotate <0,0,151.264>
	 translate <58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,38.2373>
	 rotate <0,44.8921,0>
	 rotate <0,0,59.8721>
	 translate <58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-165>
	 translate <58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,45>
	 translate <58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,46.1665>
	 rotate <0,126.706,0>
	 rotate <0,0,-177.48>
	 translate <58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.6772>
	 rotate <0,164.202,0>
	 rotate <0,0,160.298>
	 translate <58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,38.5864>
	 rotate <0,135.653,0>
	 rotate <0,0,55.5172>
	 translate <58.8337,-101.903,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.712,0>
	 rotate <0,0,-62.588>
	 translate <52.5183,-101.266,-23.6484>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-45>
	 translate <82.316,-82.316,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9896,0>
	 rotate <0,0,-62.5345>
	 translate <51.6474,-99.3596,32.1321>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<0.905185,-3.3782,0.135749>,<30.7763,-114.859,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<101.903,-58.8337,4.41158>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,39.9895>
	 rotate <0,47.3596,0>
	 rotate <0,0,89.77>
	 translate <101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,43.6845>
	 rotate <0,51.6766,0>
	 rotate <0,0,-150.189>
	 translate <101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.2999>
	 rotate <0,16.8236,0>
	 rotate <0,0,167.258>
	 translate <101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,75>
	 translate <101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.4545>
	 rotate <0,90,0>
	 rotate <0,0,-135>
	 translate <101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,40.3916>
	 rotate <0,133.091,0>
	 rotate <0,0,85.7845>
	 translate <101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,44.1935>
	 rotate <0,128.638,0>
	 rotate <0,0,-146.799>
	 translate <101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.3048>
	 rotate <0,167.133,0>
	 rotate <0,0,173.641>
	 translate <101.903,-58.8337,4.41158>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-45>
	 translate <82.316,-82.316,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-15>
	 translate <112.446,-30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,74.0024,0>
	 rotate <0,0,-31.2673>
	 translate <95.7226,-58.1254,32.107>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<2.92863,-1.78022,-0.70989>,<99.5735,-60.5274,-24.1363>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<106.239,0,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.1794>
	 rotate <0,11.699,0>
	 rotate <0,0,0>
	 translate <106.239,0,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,40.3916>
	 rotate <0,46.9087,0>
	 rotate <0,0,94.2155>
	 translate <106.239,0,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,40.3916>
	 rotate <0,46.9087,0>
	 rotate <0,0,-94.2155>
	 translate <106.239,0,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,106.364>
	 translate <106.239,0,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-106.364>
	 translate <106.239,0,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.1794>
	 rotate <0,140.609,0>
	 rotate <0,0,180>
	 translate <106.239,0,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,46.942>
	 rotate <0,117.641,0>
	 rotate <0,0,138.51>
	 translate <106.239,0,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,46.942>
	 rotate <0,117.641,0>
	 rotate <0,0,-138.51>
	 translate <106.239,0,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,16.3636>
	 translate <100.055,29.3788,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<3.00594,-0.882625,-1.56054>,<102.202,-30.0092,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<2.7049,0,-2.22115>,<91.9667,0,-75.519>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<3.42729,0,-0.709698>,<116.528,0,-24.1297>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<89.3743,57.4374,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,42.2648>
	 rotate <0,49.2406,0>
	 rotate <0,0,-63.7756>
	 translate <89.3743,57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.3048>
	 rotate <0,12.8669,0>
	 rotate <0,0,6.35933>
	 translate <89.3743,57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,38.5864>
	 rotate <0,44.3467,0>
	 rotate <0,0,124.483>
	 translate <89.3743,57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-73.6364>
	 translate <89.3743,57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,139.091>
	 translate <89.3743,57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,37.2606>
	 rotate <0,125.766,0>
	 rotate <0,0,-108.215>
	 translate <89.3743,57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.4917>
	 rotate <0,133.752,0>
	 rotate <0,0,-177.053>
	 translate <89.3743,57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.702,0>
	 rotate <0,0,31.294>
	 translate <97.4816,59.2558,-23.6292>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,16.3636>
	 translate <100.055,29.3788,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.594,0>
	 rotate <0,0,59.8678>
	 translate <45.0657,77.6418,-74.2502>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.752,0>
	 rotate <0,0,40.1691>
	 translate <68.4424,57.7751,-74.4979>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<2.05158,2.36765,-1.56054>,<69.7536,80.5,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<44.1334,96.6388,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,44.1935>
	 rotate <0,51.3625,0>
	 rotate <0,0,-33.2013>
	 translate <44.1334,96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.6772>
	 rotate <0,15.7978,0>
	 rotate <0,0,19.7024>
	 translate <44.1334,96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.8635>
	 rotate <0,41.5355,0>
	 rotate <0,0,154.523>
	 translate <44.1334,96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-40.9091>
	 translate <44.1334,96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,171.818>
	 translate <44.1334,96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.0947>
	 rotate <0,136.356,0>
	 rotate <0,0,-90.2676>
	 translate <44.1334,96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,39.5449>
	 rotate <0,123.416,0>
	 rotate <0,0,-154.968>
	 translate <44.1334,96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.712,0>
	 rotate <0,0,62.588>
	 translate <52.5183,101.266,-23.6484>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,81.8182>
	 translate <14.8405,103.218,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.594,0>
	 rotate <0,0,59.8678>
	 translate <45.0657,77.6418,-74.2502>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.752,0>
	 rotate <0,0,40.1691>
	 translate <68.4424,57.7751,-74.4979>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<2.05158,2.36765,-1.56054>,<69.7536,80.5,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-15.1194,105.158,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,46.1665>
	 rotate <0,53.2942,0>
	 rotate <0,0,-2.52032>
	 translate <-15.1194,105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.2865>
	 rotate <0,19.5741,0>
	 rotate <0,0,39.6031>
	 translate <-15.1194,105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,35.2394>
	 rotate <0,38.4597,0>
	 rotate <0,0,-175.741>
	 translate <-15.1194,105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-8.18182>
	 translate <-15.1194,105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-155.455>
	 translate <-15.1194,105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,44.4157>
	 rotate <0,119.362,0>
	 rotate <0,0,-40.2855>
	 translate <-15.1194,105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.3996>
	 rotate <0,140.071,0>
	 rotate <0,0,-90.8838>
	 translate <-15.1194,105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,81.8182>
	 translate <14.8405,103.218,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,114.545>
	 translate <-43.3191,94.8555,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.728,0>
	 rotate <0,0,93.8818>
	 translate <-7.72213,113.806,-23.6805>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-1.32748,2.32002,-2.25948>,<-45.1345,78.8808,-76.8225>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-1.15188,3.22516,-0.722174>,<-39.1641,109.655,-24.5539>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-0.471693,2.66257,-2.22221>,<-16.0375,90.5275,-75.555>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-69.572,80.2904,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,30.117>
	 rotate <0,23.6193,0>
	 rotate <0,0,63.5791>
	 translate <-69.572,80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,33.732>
	 rotate <0,35.1113,0>
	 rotate <0,0,-146.429>
	 translate <-69.572,80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,24.5455>
	 translate <-69.572,80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-122.727>
	 translate <-69.572,80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,35.1264>
	 rotate <0,128.315,0>
	 rotate <0,0,-12.1314>
	 translate <-69.572,80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,33.1868>
	 rotate <0,131.012,0>
	 rotate <0,0,-83.0298>
	 translate <-69.572,80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,147.273>
	 translate <-87.7251,56.3775,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.751,0>
	 rotate <0,0,125.175>
	 translate <-65.7069,93.2307,-23.7255>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.957,0>
	 rotate <0,0,140.2>
	 translate <-68.6081,57.1626,-74.8171>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,114.545>
	 translate <-43.3191,94.8555,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.481,0>
	 rotate <0,0,159.909>
	 translate <-84.4471,30.8877,-74.0736>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,156.469>
	 translate <-104.562,45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.858,0>
	 rotate <0,0,140.946>
	 translate <-88.538,71.8342,-23.9397>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-1.32748,2.32002,-2.25948>,<-45.1345,78.8808,-76.8225>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-1.15188,3.22516,-0.722174>,<-39.1641,109.655,-24.5539>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-101.936,29.9311,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,31.1492>
	 rotate <0,27.6415,0>
	 rotate <0,0,89.9344>
	 translate <-101.936,29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.3615>
	 rotate <0,31.4956,0>
	 rotate <0,0,-117.726>
	 translate <-101.936,29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,57.2727>
	 translate <-101.936,29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-90>
	 translate <-101.936,29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.0486>
	 rotate <0,138.565,0>
	 rotate <0,0,0.962934>
	 translate <-101.936,29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,41.9408>
	 rotate <0,121.282,0>
	 rotate <0,0,-57.5717>
	 translate <-101.936,29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,-172.239>
	 translate <-112.987,-15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-180>
	 translate <-104.279,-1.27705e-14,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,147.273>
	 translate <-87.7251,56.3775,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,165>
	 translate <-112.446,30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,172.239>
	 translate <-112.987,15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.957,0>
	 rotate <0,0,140.2>
	 translate <-68.6081,57.1626,-74.8171>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.481,0>
	 rotate <0,0,159.909>
	 translate <-84.4471,30.8877,-74.0736>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,156.469>
	 translate <-104.562,45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.858,0>
	 rotate <0,0,140.946>
	 translate <-88.538,71.8342,-23.9397>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-101.936,-29.9311,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,32.3615>
	 rotate <0,31.4956,0>
	 rotate <0,0,117.726>
	 translate <-101.936,-29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.1492>
	 rotate <0,27.6415,0>
	 rotate <0,0,-89.9344>
	 translate <-101.936,-29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,90>
	 translate <-101.936,-29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-57.2727>
	 translate <-101.936,-29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,41.9408>
	 rotate <0,121.282,0>
	 rotate <0,0,57.5717>
	 translate <-101.936,-29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.0486>
	 rotate <0,138.565,0>
	 rotate <0,0,-0.962934>
	 translate <-101.936,-29.9311,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,-172.239>
	 translate <-112.987,-15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-180>
	 translate <-104.279,-1.27705e-14,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,172.239>
	 translate <-112.987,15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,-156.469>
	 translate <-104.562,-45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-147.273>
	 translate <-87.7251,-56.3775,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-165>
	 translate <-112.446,-30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-2.53704,-0.927955,-2.22539>,<-86.2592,-31.5505,-75.6631>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-2.06119,-1.71733,-2.24773>,<-70.0804,-58.3893,-76.4227>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-69.572,-80.2904,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,33.732>
	 rotate <0,35.1113,0>
	 rotate <0,0,146.429>
	 translate <-69.572,-80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.117>
	 rotate <0,23.6193,0>
	 rotate <0,0,-63.5791>
	 translate <-69.572,-80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,122.727>
	 translate <-69.572,-80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-24.5455>
	 translate <-69.572,-80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,33.1868>
	 rotate <0,131.012,0>
	 rotate <0,0,83.0298>
	 translate <-69.572,-80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,35.1264>
	 rotate <0,128.315,0>
	 rotate <0,0,12.1314>
	 translate <-69.572,-80.2904,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.908,0>
	 rotate <0,0,-109.655>
	 translate <-38.3413,-107.352,-24.0381>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,-156.469>
	 translate <-104.562,-45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-147.273>
	 translate <-87.7251,-56.3775,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-1.32748,-2.32002,-2.25948>,<-45.1345,-78.8808,-76.8225>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-2.06119,-1.71733,-2.24773>,<-70.0804,-58.3893,-76.4227>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-1.30143,-2.84974,-1.56054>,<-44.2487,-96.8911,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-1.97403,-2.80092,-0.712784>,<-67.1169,-95.2313,-24.2347>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-2.65994,-2.15811,-0.719218>,<-90.438,-73.3757,-24.4534>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-15.1194,-105.158,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,35.2394>
	 rotate <0,38.4597,0>
	 rotate <0,0,175.741>
	 translate <-15.1194,-105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.2865>
	 rotate <0,19.5741,0>
	 rotate <0,0,-39.6031>
	 translate <-15.1194,-105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,46.1665>
	 rotate <0,53.2942,0>
	 rotate <0,0,2.52032>
	 translate <-15.1194,-105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,155.455>
	 translate <-15.1194,-105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,8.18182>
	 translate <-15.1194,-105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.3996>
	 rotate <0,140.071,0>
	 rotate <0,0,90.8838>
	 translate <-15.1194,-105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,44.4157>
	 rotate <0,119.362,0>
	 rotate <0,0,40.2855>
	 translate <-15.1194,-105.158,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.908,0>
	 rotate <0,0,-109.655>
	 translate <-38.3413,-107.352,-24.0381>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-1.32748,-2.32002,-2.25948>,<-45.1345,-78.8808,-76.8225>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-0.231995,-3.41907,-0.711431>,<-7.88784,-116.248,-24.1887>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-1.30143,-2.84974,-1.56054>,<-44.2487,-96.8911,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-0.471693,-2.66257,-2.22221>,<-16.0375,-90.5275,-75.555>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<0.44585,-3.10096,-1.56054>,<15.1589,-105.433,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<44.1334,-96.6388,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,36.8635>
	 rotate <0,41.5355,0>
	 rotate <0,0,-154.523>
	 translate <44.1334,-96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.6772>
	 rotate <0,15.7978,0>
	 rotate <0,0,-19.7024>
	 translate <44.1334,-96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,44.1935>
	 rotate <0,51.3625,0>
	 rotate <0,0,33.2013>
	 translate <44.1334,-96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-171.818>
	 translate <44.1334,-96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,40.9091>
	 translate <44.1334,-96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,39.5449>
	 rotate <0,123.416,0>
	 rotate <0,0,154.968>
	 translate <44.1334,-96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.0947>
	 rotate <0,136.356,0>
	 rotate <0,0,90.2676>
	 translate <44.1334,-96.6388,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.712,0>
	 rotate <0,0,-62.588>
	 translate <52.5183,-101.266,-23.6484>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-49.0909>
	 translate <68.2882,-78.8088,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.752,0>
	 rotate <0,0,-40.1691>
	 translate <68.4424,-57.7751,-74.4979>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.594,0>
	 rotate <0,0,-59.8678>
	 translate <45.0657,-77.6418,-74.2502>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<0.44585,-3.10096,-1.56054>,<15.1589,-105.433,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<89.3743,-57.4374,-50.7765>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,42.2648>
	 rotate <0,49.2406,0>
	 rotate <0,0,63.7756>
	 translate <89.3743,-57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,38.5864>
	 rotate <0,44.3467,0>
	 rotate <0,0,-124.483>
	 translate <89.3743,-57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.3048>
	 rotate <0,12.8669,0>
	 rotate <0,0,-6.35933>
	 translate <89.3743,-57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,73.6364>
	 translate <89.3743,-57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.9311>
	 rotate <0,90,0>
	 rotate <0,0,-139.091>
	 translate <89.3743,-57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,37.2606>
	 rotate <0,125.766,0>
	 rotate <0,0,108.215>
	 translate <89.3743,-57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.4917>
	 rotate <0,133.752,0>
	 rotate <0,0,177.053>
	 translate <89.3743,-57.4374,-50.7765>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-49.0909>
	 translate <68.2882,-78.8088,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.752,0>
	 rotate <0,0,-40.1691>
	 translate <68.4424,-57.7751,-74.4979>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.594,0>
	 rotate <0,0,-59.8678>
	 translate <45.0657,-77.6418,-74.2502>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<3.00594,-0.882625,-1.56054>,<102.202,-30.0092,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<2.92863,-1.78022,-0.70989>,<99.5735,-60.5274,-24.1363>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<70.4733,0,-94.3323>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.1794>
	 rotate <0,39.3913,0>
	 rotate <0,0,0>
	 translate <70.4733,0,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,37.2606>
	 rotate <0,54.2341,0>
	 rotate <0,0,71.7851>
	 translate <70.4733,0,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,37.2606>
	 rotate <0,54.2341,0>
	 rotate <0,0,-71.7851>
	 translate <70.4733,0,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,115.714>
	 translate <70.4733,0,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,-115.714>
	 translate <70.4733,0,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.1794>
	 rotate <0,112.916,0>
	 rotate <0,0,180>
	 translate <70.4733,0,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,45.8503>
	 rotate <0,103.846,0>
	 rotate <0,0,180>
	 translate <70.4733,0,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,158.415,0>
	 rotate <0,0,-41.3976>
	 translate <32.1489,-28.3407,-108.331>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,25.7143>
	 translate <58.6097,28.2249,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.084,0>
	 rotate <0,0,0>
	 translate <45.3636,0,-107.305>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,158.415,0>
	 rotate <0,0,41.3976>
	 translate <32.1489,28.3407,-108.331>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<1.76081,-0.847959,-2.90354>,<59.8674,-28.8306,-98.7203>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<2.7049,0,-2.22115>,<91.9667,0,-75.519>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<43.9394,55.0983,-94.3323>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,46.942>
	 rotate <0,62.3589,0>
	 rotate <0,0,-41.4896>
	 translate <43.9394,55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.4917>
	 rotate <0,46.2475,0>
	 rotate <0,0,2.94713>
	 translate <43.9394,55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.0947>
	 rotate <0,43.6437,0>
	 rotate <0,0,89.7324>
	 translate <43.9394,55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,44.4157>
	 rotate <0,60.6384,0>
	 rotate <0,0,139.715>
	 translate <43.9394,55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,-64.2857>
	 translate <43.9394,55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,167.143>
	 translate <43.9394,55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.2544>
	 rotate <0,109.889,0>
	 rotate <0,0,-114.73>
	 translate <43.9394,55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,43.0811>
	 rotate <0,104.756,0>
	 rotate <0,0,-138.602>
	 translate <43.9394,55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,25.7143>
	 translate <58.6097,28.2249,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.084,0>
	 rotate <0,0,0>
	 translate <45.3636,0,-107.305>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.594,0>
	 rotate <0,0,59.8678>
	 translate <45.0657,77.6418,-74.2502>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,158.415,0>
	 rotate <0,0,41.3976>
	 translate <32.1489,28.3407,-108.331>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.752,0>
	 rotate <0,0,40.1691>
	 translate <68.4424,57.7751,-74.4979>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<0.434883,1.90535,-2.90354>,<14.786,64.7818,-98.7203>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-15.6818,68.7064,-94.3323>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,39.5449>
	 rotate <0,56.584,0>
	 rotate <0,0,25.0315>
	 translate <-15.6818,68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.3996>
	 rotate <0,39.9292,0>
	 rotate <0,0,89.1162>
	 translate <-15.6818,68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,35.1264>
	 rotate <0,51.6848,0>
	 rotate <0,0,167.869>
	 translate <-15.6818,68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,-12.8571>
	 translate <-15.6818,68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,-141.429>
	 translate <-15.6818,68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,39.9213>
	 rotate <0,105.954,0>
	 rotate <0,0,-63.5076>
	 translate <-15.6818,68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.0918>
	 rotate <0,107.699,0>
	 rotate <0,0,-92.401>
	 translate <-15.6818,68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,114.545>
	 translate <-43.3191,94.8555,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,128.571>
	 translate <-40.5592,50.8596,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-1.32748,2.32002,-2.25948>,<-45.1345,78.8808,-76.8225>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<0.434883,1.90535,-2.90354>,<14.786,64.7818,-98.7203>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-0.471693,2.66257,-2.22221>,<-16.0375,90.5275,-75.555>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-63.4943,30.5772,-94.3323>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,33.1868>
	 rotate <0,48.9876,0>
	 rotate <0,0,96.9702>
	 translate <-63.4943,30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.0486>
	 rotate <0,41.4352,0>
	 rotate <0,0,-179.037>
	 translate <-63.4943,30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,41.9408>
	 rotate <0,58.7179,0>
	 rotate <0,0,-122.428>
	 translate <-63.4943,30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,38.5714>
	 translate <-63.4943,30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,-90>
	 translate <-63.4943,30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,45.1384>
	 rotate <0,104.069,0>
	 rotate <0,0,-20.4371>
	 translate <-63.4943,30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.3062>
	 rotate <0,111.988,0>
	 rotate <0,0,-34.2364>
	 translate <-63.4943,30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,147.273>
	 translate <-87.7251,56.3775,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.957,0>
	 rotate <0,0,140.2>
	 translate <-68.6081,57.1626,-74.8171>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.481,0>
	 rotate <0,0,159.909>
	 translate <-84.4471,30.8877,-74.0736>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,128.571>
	 translate <-40.5592,50.8596,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.423,0>
	 rotate <0,0,-159.563>
	 translate <-41.9117,-15.6178,-107.572>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,180>
	 translate <-65.0518,7.96655e-15,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.423,0>
	 rotate <0,0,159.563>
	 translate <-41.9117,15.6178,-107.572>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-63.4943,-30.5772,-94.3323>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,41.9408>
	 rotate <0,58.7179,0>
	 rotate <0,0,122.428>
	 translate <-63.4943,-30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.0486>
	 rotate <0,41.4352,0>
	 rotate <0,0,179.037>
	 translate <-63.4943,-30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,33.1868>
	 rotate <0,48.9876,0>
	 rotate <0,0,-96.9702>
	 translate <-63.4943,-30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,90>
	 translate <-63.4943,-30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,-38.5714>
	 translate <-63.4943,-30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,45.1384>
	 rotate <0,104.069,0>
	 rotate <0,0,20.4371>
	 translate <-63.4943,-30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.3062>
	 rotate <0,111.988,0>
	 rotate <0,0,34.2364>
	 translate <-63.4943,-30.5772,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,-128.571>
	 translate <-40.5592,-50.8596,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.423,0>
	 rotate <0,0,-159.563>
	 translate <-41.9117,-15.6178,-107.572>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,180>
	 translate <-65.0518,7.96655e-15,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-147.273>
	 translate <-87.7251,-56.3775,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.423,0>
	 rotate <0,0,159.563>
	 translate <-41.9117,15.6178,-107.572>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-2.53704,-0.927955,-2.22539>,<-86.2592,-31.5505,-75.6631>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-2.06119,-1.71733,-2.24773>,<-70.0804,-58.3893,-76.4227>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-15.6818,-68.7064,-94.3323>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,35.1264>
	 rotate <0,51.6848,0>
	 rotate <0,0,-167.869>
	 translate <-15.6818,-68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,28.3996>
	 rotate <0,39.9292,0>
	 rotate <0,0,-89.1162>
	 translate <-15.6818,-68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,39.5449>
	 rotate <0,56.584,0>
	 rotate <0,0,-25.0315>
	 translate <-15.6818,-68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,141.429>
	 translate <-15.6818,-68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,12.8571>
	 translate <-15.6818,-68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,39.9213>
	 rotate <0,105.954,0>
	 rotate <0,0,63.5076>
	 translate <-15.6818,-68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.0918>
	 rotate <0,107.699,0>
	 rotate <0,0,92.401>
	 translate <-15.6818,-68.7064,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,-128.571>
	 translate <-40.5592,-50.8596,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,-77.1429>
	 translate <14.4754,-63.4209,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<-1.32748,-2.32002,-2.25948>,<-45.1345,-78.8808,-76.8225>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	cylinder {
	<-0.471693,-2.66257,-2.22221>,<-16.0375,-90.5275,-75.555>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<43.9394,-55.0983,-94.3323>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,46.942>
	 rotate <0,62.3589,0>
	 rotate <0,0,41.4896>
	 translate <43.9394,-55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,44.4157>
	 rotate <0,60.6384,0>
	 rotate <0,0,-139.715>
	 translate <43.9394,-55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.0947>
	 rotate <0,43.6437,0>
	 rotate <0,0,-89.7324>
	 translate <43.9394,-55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,31.4917>
	 rotate <0,46.2475,0>
	 rotate <0,0,-2.94713>
	 translate <43.9394,-55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,64.2857>
	 translate <43.9394,-55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,30.5772>
	 rotate <0,90,0>
	 rotate <0,0,-167.143>
	 translate <43.9394,-55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.2544>
	 rotate <0,109.889,0>
	 rotate <0,0,114.73>
	 translate <43.9394,-55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,43.0811>
	 rotate <0,104.756,0>
	 rotate <0,0,138.602>
	 translate <43.9394,-55.0983,-94.3323>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,158.415,0>
	 rotate <0,0,-41.3976>
	 translate <32.1489,-28.3407,-108.331>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-49.0909>
	 translate <68.2882,-78.8088,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.752,0>
	 rotate <0,0,-40.1691>
	 translate <68.4424,-57.7751,-74.4979>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.084,0>
	 rotate <0,0,0>
	 translate <45.3636,0,-107.305>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.594,0>
	 rotate <0,0,-59.8678>
	 translate <45.0657,-77.6418,-74.2502>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,-77.1429>
	 translate <14.4754,-63.4209,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	cylinder {
	<1.76081,-0.847959,-2.90354>,<59.8674,-28.8306,-98.7203>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<18.5626,0,-116.278>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,28.1794>
	 rotate <0,67.0836,0>
	 rotate <0,0,0>
	 translate <18.5626,0,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.2544>
	 rotate <0,70.1114,0>
	 rotate <0,0,65.2705>
	 translate <18.5626,0,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,39.9213>
	 rotate <0,74.0464,0>
	 rotate <0,0,116.492>
	 translate <18.5626,0,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,45.1384>
	 rotate <0,75.931,0>
	 rotate <0,0,159.563>
	 translate <18.5626,0,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,45.1384>
	 rotate <0,75.931,0>
	 rotate <0,0,-159.563>
	 translate <18.5626,0,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,39.9213>
	 rotate <0,74.0464,0>
	 rotate <0,0,-116.492>
	 translate <18.5626,0,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,32.2544>
	 rotate <0,70.1114,0>
	 rotate <0,0,-65.2705>
	 translate <18.5626,0,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,18.5626>
	 rotate <0,90,0>
	 rotate <0,0,180>
	 translate <18.5626,0,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,158.415,0>
	 rotate <0,0,-41.3976>
	 translate <32.1489,-28.3407,-108.331>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,25.7143>
	 translate <58.6097,28.2249,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.084,0>
	 rotate <0,0,0>
	 translate <45.3636,0,-107.305>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,180,0>
	 rotate <0,0,90>
	 translate <8.7361e-31,1.42671e-14,-116.5>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,158.415,0>
	 rotate <0,0,41.3976>
	 translate <32.1489,28.3407,-108.331>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

difference {
	intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <1,1,0,0.4> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	sphere {
	<-18.5626,2.27327e-15,-116.278>,
	48
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	box {
	<-48,-48,-48>,<48,48,45.8503>
	 rotate <0,76.1538,0>
	 rotate <0,0,-1.46288e-15>
	 translate <-18.5626,2.27327e-15,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,43.0811>
	 rotate <0,75.2443,0>
	 rotate <0,0,41.3976>
	 translate <-18.5626,2.27327e-15,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.0918>
	 rotate <0,72.3007,0>
	 rotate <0,0,87.599>
	 translate <-18.5626,2.27327e-15,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.3062>
	 rotate <0,68.0118,0>
	 rotate <0,0,145.764>
	 translate <-18.5626,2.27327e-15,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,29.3062>
	 rotate <0,68.0118,0>
	 rotate <0,0,-145.764>
	 translate <-18.5626,2.27327e-15,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,36.0918>
	 rotate <0,72.3007,0>
	 rotate <0,0,-87.599>
	 translate <-18.5626,2.27327e-15,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,43.0811>
	 rotate <0,75.2443,0>
	 rotate <0,0,-41.3976>
	 translate <-18.5626,2.27327e-15,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	box {
	<-48,-48,-48>,<48,48,18.5626>
	 rotate <0,90,0>
	 rotate <0,0,-3.50835e-15>
	 translate <-18.5626,2.27327e-15,-116.278>
	pigment { color rgbt <1,1,0,0.4> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.423,0>
	 rotate <0,0,-159.563>
	 translate <-41.9117,-15.6178,-107.572>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,180>
	 translate <-65.0518,7.96655e-15,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,180,0>
	 rotate <0,0,90>
	 translate <8.7361e-31,1.42671e-14,-116.5>
	pigment { color rgbt <0,1,1,0.4> }
	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.423,0>
	 rotate <0,0,159.563>
	 translate <-41.9117,15.6178,-107.572>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,-172.239>
	 translate <-112.987,-15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,-109.871>
	 translate <-38.0127,-105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,49.0909>
	 translate <65.4817,75.5699,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.712,0>
	 rotate <0,0,62.588>
	 translate <52.5183,101.266,-23.6484>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,74.0067,0>
	 rotate <0,0,0>
	 translate <111.991,0,32.0986>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-180>
	 translate <-104.279,-1.27705e-14,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,147.273>
	 translate <-87.7251,56.3775,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-105>
	 translate <-30.1297,-112.446,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,165>
	 translate <-112.446,30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.712,0>
	 rotate <0,0,-62.588>
	 translate <52.5183,-101.266,-23.6484>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-16.3636>
	 translate <95.9428,-28.1714,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-49.0909>
	 translate <65.4817,-75.5699,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,158.415,0>
	 rotate <0,0,-41.3976>
	 translate <32.1489,-28.3407,-108.331>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,105>
	 translate <-30.1297,112.446,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,172.4>
	 translate <-110.92,14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-49.0909>
	 translate <68.2882,-78.8088,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.751,0>
	 rotate <0,0,125.175>
	 translate <-65.7069,93.2307,-23.7255>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.816,0>
	 rotate <0,0,172.239>
	 translate <-112.987,15.3997,-23.855>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,114.545>
	 translate <-41.5387,90.9571,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,81.8182>
	 translate <14.8405,103.218,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9896,0>
	 rotate <0,0,62.5345>
	 translate <51.6474,99.3596,32.1321>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9682,0>
	 rotate <0,0,-93.8014>
	 translate <-7.42339,-111.723,32.174>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.957,0>
	 rotate <0,0,140.2>
	 translate <-68.6081,57.1626,-74.8171>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.908,0>
	 rotate <0,0,-109.655>
	 translate <-38.3413,-107.352,-24.0381>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-45>
	 translate <82.316,-82.316,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,114.545>
	 translate <-43.3191,94.8555,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.702,0>
	 rotate <0,0,31.294>
	 translate <97.4816,59.2558,-23.6292>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.752,0>
	 rotate <0,0,-40.1691>
	 translate <68.4424,-57.7751,-74.4979>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-114.545>
	 translate <-41.5387,-90.9571,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.481,0>
	 rotate <0,0,159.909>
	 translate <-84.4471,30.8877,-74.0736>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-81.8182>
	 translate <14.2305,-98.9755,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-15>
	 translate <112.446,-30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,141.135>
	 translate <-87.1062,70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,25.7143>
	 translate <58.6097,28.2249,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,156.469>
	 translate <-104.562,45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.084,0>
	 rotate <0,0,0>
	 translate <45.3636,0,-107.305>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,-128.571>
	 translate <-40.5592,-50.8596,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9896,0>
	 rotate <0,0,-62.5345>
	 translate <51.6474,-99.3596,32.1321>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,128.571>
	 translate <-40.5592,50.8596,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,147.273>
	 translate <-84.1197,54.0604,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,125.068>
	 translate <-64.322,91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.594,0>
	 rotate <0,0,-59.8678>
	 translate <45.0657,-77.6418,-74.2502>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.78,0>
	 rotate <0,0,-156.469>
	 translate <-104.562,-45.5333,-23.7836>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9381,0>
	 rotate <0,0,-125.068>
	 translate <-64.322,-91.6296,32.2328>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,16.3636>
	 translate <100.055,29.3788,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.7293,0>
	 rotate <0,0,109.871>
	 translate <-38.0127,105.175,32.6406>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,-77.1429>
	 translate <14.4754,-63.4209,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.9682,0>
	 rotate <0,0,93.8014>
	 translate <-7.42339,111.723,32.174>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.423,0>
	 rotate <0,0,-159.563>
	 translate <-41.9117,-15.6178,-107.572>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,146.056,0>
	 rotate <0,0,180>
	 translate <-65.0518,7.96655e-15,-96.6463>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,16.3636>
	 translate <95.9428,28.1714,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,74.0024,0>
	 rotate <0,0,31.2673>
	 translate <95.7226,58.1254,32.107>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,75>
	 translate <30.1297,112.446,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.594,0>
	 rotate <0,0,59.8678>
	 translate <45.0657,77.6418,-74.2502>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,116.479,0>
	 rotate <0,0,-147.273>
	 translate <-87.7251,-56.3775,-51.9436>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,180,0>
	 rotate <0,0,90>
	 translate <8.7361e-31,1.42671e-14,-116.5>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.728,0>
	 rotate <0,0,93.8818>
	 translate <-7.72213,113.806,-23.6805>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,74.0024,0>
	 rotate <0,0,-31.2673>
	 translate <95.7226,-58.1254,32.107>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,158.415,0>
	 rotate <0,0,41.3976>
	 translate <32.1489,28.3407,-108.331>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,81.8182>
	 translate <14.2305,98.9755,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,156.334>
	 translate <-102.517,44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-147.273>
	 translate <-84.1197,-54.0604,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,87.7772,0>
	 rotate <0,0,-165>
	 translate <-112.446,-30.1297,4.51849>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,59.1275,0>
	 rotate <0,0,-180>
	 translate <-99.9933,-1.22456e-14,59.7796>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.795,0>
	 rotate <0,0,-141.135>
	 translate <-87.1062,-70.1976,32.5123>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8516,0>
	 rotate <0,0,-172.4>
	 translate <-110.92,-14.7997,32.4017>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,157.423,0>
	 rotate <0,0,159.563>
	 translate <-41.9117,15.6178,-107.572>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,129.752,0>
	 rotate <0,0,40.1691>
	 translate <68.4424,57.7751,-74.4979>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,73.8992,0>
	 rotate <0,0,-156.334>
	 translate <-102.517,-44.9289,32.3086>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,1,1,0.4> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

	box {
	<-119,-119,-119>,<119,119,57.967>
	pigment { color rgbt <1,1,0,0.3> }
	}

	}

	box {
	<-4.67,-4.67,-4.67>,<4.67,4.67,4.67>
	 rotate <0,101.858,0>
	 rotate <0,0,140.946>
	 translate <-88.538,71.8342,-23.9397>
	pigment { color rgbt <0,1,1,0.4> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-83.7222,-30.6225,-73.4377>,<-86.2592,-31.5505,-75.6631>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<58.1066,-27.9827,-95.8167>,<59.8674,-28.8306,-98.7203>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<29.8711,-111.48,4.4797>,<30.7763,-114.859,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<111.48,29.8711,4.4797>,<114.859,30.7763,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-43.807,-76.5608,-74.563>,<-45.1345,-78.8808,-76.8225>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-43.807,76.5608,-74.563>,<-45.1345,78.8808,-76.8225>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<99.1961,-29.1266,-51.4977>,<102.202,-30.0092,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<81.6094,81.6094,4.4797>,<84.0824,84.0824,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<14.3511,62.8765,-95.8167>,<14.786,64.7818,-98.7203>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<67.7021,78.1323,-51.4977>,<69.7536,80.5,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-68.0192,-56.672,-74.1749>,<-70.0804,-58.3893,-76.4227>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-38.0122,106.43,-23.8317>,<-39.1641,109.655,-24.5539>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-7.65585,-112.829,-23.4772>,<-7.88784,-116.248,-24.1887>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-42.9472,-94.0413,-51.4977>,<-44.2487,-96.8911,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-65.1428,-92.4304,-23.5219>,<-67.1169,-95.2313,-24.2347>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-15.5659,87.865,-73.3328>,<-16.0375,90.5275,-75.555>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<89.2618,0,-73.2979>,<91.9667,0,-75.519>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-81.6094,81.6094,4.4797>,<-84.0824,84.0824,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-15.5659,-87.865,-73.3328>,<-16.0375,-90.5275,-75.555>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<14.7131,-102.332,-51.4977>,<15.1589,-105.433,-53.0583>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-87.778,-71.2176,-23.7342>,<-90.438,-73.3757,-24.4534>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<113.101,0,-23.42>,<116.528,0,-24.1297>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<-81.6094,-81.6094,4.4797>,<-84.0824,-84.0824,4.61545>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

intersection {
	difference {
	sphere {
	<0,0,0>,
	119
	pigment { color rgbt <0,0,0,0.5> }
	}

	sphere {
	<0,0,0>,
	116.5
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

	cylinder {
	<96.6448,-58.7472,-23.4264>,<99.5735,-60.5274,-24.1363>,2.99
	pigment { color rgbt <0,0,0,0.5> }
	}

	}

difference {
	intersection {
	sphere {
	<36.7531,-107.419,-14.8505>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<110.125,-27.3993,-15.2316>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<62.981,-28.8378,-91.1703>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<-82.1988,79.3493,-7.56986>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<16.7617,-104.107,-44.6205>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<92.3091,20.8865,-64.444>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<-28.1267,-45.1086,-101.412>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<63.9412,81.8909,48.1213>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<-95.2425,58.4636,24.9224>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<-97.5744,-53.106,-27.7351>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<-74.2481,-80.5635,33.2715>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<-95.3689,-40.5161,48.7183>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

difference {
	intersection {
	sphere {
	<-86.2152,57.6486,48.5162>,
	10.706
	pigment { color rgbt <0,1,0,0.45> }
	}

	sphere {
	<0,0,0>,
	114.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

	sphere {
	<0,0,0>,
	66.5
	pigment { color rgbt <0,1,0,0.45> }
	}

	}

sphere {
	<35.5585,-108.836,-0.689805>,
	1.4039
	pigment { color rgbt <1,0,0,0.675511> }
	}

