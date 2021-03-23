DeleteTicket()
{
	web_reg_save_param_ex(
		"ParamName=CompSession1",
		"LB=userSession\" value=\"",
		"RB=\"/>",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
	web_url("Webtours",
		"URL=http://localhost:1080/Webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);


	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={CompSession1}", ENDITEM, 
		"Name=username", "Value={UserDeletete}", ENDITEM, 
		"Name=password", "Value={PasswordDeletete}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=69", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=flightID",
		"LB=flightID\" value=\"",
		"RB=\"",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		LAST);
	
	web_reg_find("Text=flightID",
		"SaveCount=Count",	             
		LAST);
	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);
	
	
	lr_output_message("Number of Tickets on page is: %s",lr_eval_string("{Count}"));
	countTicket = atoi(lr_eval_string("{Count}"));
	
	randomDelete = rand() % countTicket + 1;
	lr_save_int(randomDelete, "numberDelete");
	lr_output_message("Number of Tickets for DELETE is: %s",lr_eval_string("{numberDelete}"));
		
		web_submit_data("itinerary.pl", 
			"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=flightID", "Value={flightID_1}", ENDITEM, 
			"Name=flightID", "Value={flightID_2}", ENDITEM,
			"Name=flightID", "Value={flightID_3}", ENDITEM, 
			"Name=flightID", "Value={flightID_4}", ENDITEM, 
			"Name=flightID", "Value={flightID_5}", ENDITEM,
			"Name=flightID", "Value={flightID_6}", ENDITEM, 
			"Name=flightID", "Value={flightID_7}", ENDITEM, 
			"Name=flightID", "Value={flightID_8}", ENDITEM, 
			"Name=flightID", "Value={flightID_9}", ENDITEM, 				
			"Name={numberDelete}", "Value=on", ENDITEM, 
			"Name=flightID", "Value={flightID_10}", ENDITEM, 
			"Name=.cgifields", "Value=1", ENDITEM, 
			"Name=.cgifields", "Value=3", ENDITEM, 
			"Name=.cgifields", "Value=2", ENDITEM, 
			"Name=removeFlights.x", "Value=39", ENDITEM, 
			"Name=removeFlights.y", "Value=14", ENDITEM, 
			LAST);
	
	
	
	return 0;
}
