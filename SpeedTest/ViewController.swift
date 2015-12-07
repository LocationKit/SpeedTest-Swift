//
//  ViewController.swift
//  SpeedTest
//
//  Created by Victor Quinn on 7/30/15.
//  Copyright (c) 2015 SocialRadar. All rights reserved.
//

import UIKit

class ViewController: UIViewController, LKLocationManagerDelegate {

    @IBOutlet weak var speed: UILabel!
    
    var locationManager: LKLocationManager?

    override func viewDidLoad() {
        locationManager = initLocationManager()
        super.viewDidLoad()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func initLocationManager() -> LKLocationManager {
        let locationManager = LKLocationManager()
        locationManager.debug = true
        locationManager.apiToken = "your_api_token_here"
        locationManager.advancedDelegate = self
        locationManager.startUpdatingLocation()
        return locationManager
    }
    
    func locationManager(manager: LKLocationManager, didUpdateLocations locations: [CLLocation]) {
        for loc in locations {
            if (loc.speed > 1) {
                self.speed.text = "\(loc.speed * 2.236936) MPH"
            } else if (loc.speed >= 0 && loc.speed < 1) {
                self.speed.text = "Stopped"
            } else {
                self.speed.text = "Unknown"
            }
            
            if loc.speed > 0 {
                speed.text = "\(round(loc.speed * 2.236936)) MPH"
            } else {
                speed.text = "Not moving"
            }

        }
    }
}