"use strict";

// const http = require("http");
// const { SSL_OP_NO_SESSION_RESUMPTION_ON_RENEGOTIATION } = require("constants");

const setup = (homebridge) => {
  homebridge.registerAccessory(
    "homebridge-example",
    "ESP8266 Test",
    ESP8266Test
  );
};

class ESP8266Test {
  constructor(log, config, api) {
    log("ESP8266 Start!");
    this.log = log;
    this.config = config;
    this.api = api;

    this.Service = this.api.hap.Service;
    this.Characteristic = this.api.hap.Characteristic;

    // extract name from config
    this.name = config.name;

    // create a new Temperature Sensor service
    this.temperatureService = new this.Service.TemperatureSensor(this.name);
    // create handlers for required characteristics
    this.temperatureService
      .getCharacteristic(this.Characteristic.CurrentTemperature)
      .onGet(this.handleCurrentTemperatureGet.bind(this));
  }

  handleCurrentTemperatureGet() {
    this.log.debug("Triggered GET CurrentTemperature");

    const currentValue = 26;

    return currentValue;
  }

  getServices() {
    return [this.temperatureService];
  }
}

module.exports = setup;
