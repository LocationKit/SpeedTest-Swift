//
//  ViewController.swift
//  SpeedTest
//
//  Created by Victor Quinn on 7/30/15.
//  Copyright (c) 2015 SocialRadar. All rights reserved.
//

import UIKit

class ViewController: UIViewController, LocationKitDelegate {

    @IBOutlet weak var speed: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        LocationKit.sharedInstance().startWithApiToken("", andDelegate: self)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func locationKit(locationKit: LocationKit!, didUpdateLocation location: CLLocation!) {

        if let loc = location {
            if (location.speed > 1) {
                self.speed.text = "\(location.speed * 2.236936) MPH"
            } else if (location.speed >= 0 && location.speed < 1) {
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
