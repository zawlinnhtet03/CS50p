-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND year=2021 AND street = "Humphrey Street";
--  Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today
-- with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |

SELECT transcript FROM interviews WHERE month = 7 AND day = 28 AND year= 2021 AND transcript LIKE "%bakery%";
-- | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
-- | I'm the bakery owner, and someone came in, suspiciously whispering into a phone for about half an hour. They never bought any

SELECT name FROM people JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND minute>=15 AND minute<=25 AND activity="exit";
-- Suspects- Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey, Taylor

SELECT DISTINCT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number WHERE year=2021 AND month=7 AND day=28 AND transaction_type="withdraw" and atm_location="Leggett Street";

-- Suspects - Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista
-- Both - Bruce, Luca, Iman, Diana, Taylor

SELECT name FROM people JOIN passengers ON people.passport_number = passengers.passport_number WHERE flight_id = (SELECT id FROM flights WHERE year=2021 AND month=7 AND day=29 ORDER BY hour, minute LIMIT 1);
-- Suspects- Doris, Sofia, Bruce, Edward, Kelsey, Taylor, Kenny, Luca
--  Common suspects - Taylor, Bruce

SELECT DISTINCT name FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller WHERE year=2021 AND month=7 AND day=28 AND duration<60;

SELECT city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE year=2021 AND month=7 AND day=29);

SELECT name FROM people JOIN phone_calls ON people.phone_number=phone_calls.receiver WHERE year=2021 AND month=7 AND day=28 AND caller = (SELECT phone_number FROM people WHERE name = "Diana");