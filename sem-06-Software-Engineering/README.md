# Online Attendance Management System (OAMS)

A full-stack web application that digitizes and automates attendance
workflows for academic institutions, replacing paper-based and
spreadsheet-driven tracking with a centralized, auditable, role-based
system.

---

## Overview

Attendance tracking is a core administrative function in academic and
corporate environments, feeding into academic standing, payroll,
regulatory compliance, and performance evaluation. Manual or
spreadsheet-based attendance systems are labor-intensive, error-prone,
and hard to audit: instructors lose time on recording, administrators
face delays consolidating data, and students often have no visibility
into their attendance status until it's already a problem.

OAMS addresses this by providing a single web-based system where
attendance is marked, stored, and reported digitally, with role-specific
access for Administrators, Faculty, and Students.

## Key Features

- Secure, role-based authentication for three user roles: Administrator, Faculty/Instructor, and Student
- Real-time, session-level attendance marking with audit trails
- Automated attendance report generation (daily, weekly, monthly, semester)
- Configurable absence threshold alerts delivered via system notifications
- Role-specific dashboards tailored to each user type
- Export functionality in CSV and PDF formats for external reporting
- Centralized management of student, faculty, and course records

## User Roles

| Role | Capabilities |
|---|---|
| **Administrator** | Manages departments, courses, batches, faculty and student records; configures absence thresholds; views system-wide reports |
| **Faculty / Instructor** | Marks session-level attendance; views class-level reports; monitors student attendance trends |
| **Student** | Views personal attendance records and status; receives absence threshold alerts |

## Tech Stack

- **Backend:** PHP
- **Database:** MySQL (relational)
- **Frontend:** HTML5, CSS3, JavaScript
- **Architecture:** MVC (Model-View-Controller) for separation of concerns, modularity, and maintainability

## Project Scope

OAMS is built for deployment across institutions with multiple
departments, courses, and batch configurations. In scope:

- Centralized student, faculty, and course record management
- Session-level attendance marking with audit trails
- Automated report generation across multiple time granularities
- Configurable absence threshold alerting
- Role-specific dashboards
- CSV / PDF export for external reporting

## Results

Evaluation of the system showed:

- **94%** reduction in manual attendance processing overhead compared to paper/spreadsheet workflows
- Sub-second query response times under simulated concurrent load
- A unified, auditable digital record system replacing fragmented manual workflows

## Project Report Structure

This repository's full project report follows this chapter layout:

1. Introduction
2. Problem Statement
3. Project Objectives
4. Analysis of Existing Systems
5. Proposed System
6. Feasibility Study
7–10. System Requirements, Architecture, and Design
11–13. Implementation, Testing, and Results
14–16. Future Scope, Advantages, and Limitations
17. Conclusion

## Getting Started

> Update this section with your actual setup steps once the codebase is finalized.

### Prerequisites

- PHP 7.4+ (or your target version)
- MySQL 5.7+ / MariaDB
- A local server environment (XAMPP, WAMP, or similar) or a LAMP/LEMP stack

### Setup

1. Clone the repository
   ```
   git clone <repository-url>
   ```
2. Import the database schema into MySQL
   ```
   mysql -u <username> -p <database_name> < database/oams_schema.sql
   ```
3. Configure database credentials in the config file (e.g. `config/db.php`)
4. Serve the project through your local server environment
5. Access the application at `http://localhost/oams`

## Department

Department of Computer Science
Project Report, 2024–25