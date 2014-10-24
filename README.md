# ![logo](http://i.imgur.com/f7LUntW.png) GbCraft Private Server

A fork of [MangosBot](https://github.com/ike3/mangosbot) for use with my private server. Please refer to the [Mangosbot Document](http://ike3.github.io/mangosbot-docs/) for information on how to install. 

<br />



## Source Setup
1. Checkout the source from https://github.com/krlloyd/gbcraft.git
2. Checkout the master branch.
3. Create a build directory somewhere on the windows machine (in this example we'll use c:\builds)

## Building Prerequisites
1. Ensure you have all of the required libraries installed:

  a. GitExtensions
     
  b. Visual Studios 2013 or Visual c++ 2013 Express
  
  c. MySql Server Community Edition (5.5.x)
  
  d. Some sort of database manager. Heidi Preferred.
  
  e. Boost Library (TrinityCore Dependency)
  
  f. CMake (A build configuration tool)

 g. OpenSSL (Be sure to select right architecture x86 vs x64) do not use the light version
  
  h. ZeroMQ Library (TrinityCore Dependency)

   See: http://collab.kpsn.org/display/tc/TrinityCore+Requirements#TrinityCoreRequirements-Windows

## Building GbCraft
1. Open up CMAKE:

  a. In "Where is the source code:" field, enter in the root directory of the gbcraft repository (not the src directory).
  
 b. In "Where to build the binaries:" field, enter in the build directory. In our case c:/builds.

 c. Click Configure and you should be present with a list of checkboxed (in red).
 
 d. Check tools if you need to generate maps, vmaps, dbc and mmaps. Below is a debug configuration because I selected WITH_COREDEBUG. Remove if release is desired
![Alt text]( http://i.imgur.com/Au341pu.png)

2. Open VS Solution created in the build directory and right click ALL_BUILD and build. (Note if you want the release version change in the Build Configuration Manager.

3. When Compilation is complete. The binary files will be in the build/bin/debug or release.

4. Copy libmysql.dll from C:\Program Files\MySQL\MySQL Server 5.x\lib to where the worldserver executable is at.

5. Copy libeay32.dll and ssleay32.dll from C:\OpenSSL-Win32(or 64)\bin


## Database Installation

 For new installs (Note ensure mysql is in your environmental path)

1.  Open Command Prompt and navigate to  <GbCraftRepository>\sql\create\ directory. run mysql -u root -p. Enter password and then run source create_mysql.sql. This will create the the auth, characters and world datebases for you. They are all empty at this point. exit mysql.

2. **(Load auth and base characters data) **  Navigate to <GbCraftRepository>\sql\base and run mysql -u root -p. Enter password and then type:
    
    `use auth;`
    
    `source auth_database.sql;`
    
    `use characters;`

    `source characters_database.sql;`

3. Now that your auth and characters have their base data we can populate the world database. Exit MySQL.

4. IMPORTANT! We need to determine what trinity version our server is at. Currently we are at 57. I was able to tell this by looking at the latest wotlk branch commits from GbCraft. As you can see below ike merged trinitycore 335.57 database. We need to download that database source that to the world database.![Alt text]( http://i.imgur.com/qaHnGKR.png)

5. **(Load world data) ** Go to http://www.trinitycore.org/f/files/file/5-legacy-tdb-335-full/ and download 57 file. Unzip in the same directory as your other base files and  run mysql -u root -p. Enter password and then type :

       `use world;`

       `source TDB_full_335.57_2014_10_19.sql;`

6.  **(Load bot specific data) ** Navigate to <GbCraftRepository>\sql\ and run mysql -u root -p. Enter password and then type:
    
    `use characters;`
    
    `source characters_ai_playerbot.sql;`

     `source characters_auctionhousebot.sql;`
    
    `source characters_ai_playerbot_names.sql;`


<br/>






___

![logo](http://www.trinitycore.org/f/public/style_images/1_trinitycore.png)  

All credit to the TrinityCore Team  and Ike3 for MaNGOS-Bot port for trinitycore.


## Copyright

License: GPL 2.0

Read file [COPYING](COPYING)


