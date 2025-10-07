<template>
  <div>
    <div>
      <!-- Breadcrumb -->
      <nav>
        <RouterLink to="/courses">Courses</RouterLink>
        <span>/</span>
        <span>{{ subject }}</span>
      </nav>
      
      <!-- Course content -->
      <div>
        <h1>{{ subject }} Course</h1>
        <p>{{ getCourseDescription(subject) }}</p>
        
        <!-- Course modules -->
        <div>
          <div v-for="module in getCourseModules(subject)" :key="module">
            <h3>{{ module }}</h3>
          </div>
        </div>
        
        <div>
          <RouterLink to="/pricing">
            Enroll Now
          </RouterLink>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { RouterLink } from 'vue-router'

const props = defineProps(['subject'])

const getCourseDescription = (subject) => {
  const descriptions = {
    html: 'Master the foundation of web development with comprehensive HTML training',
    css: 'Learn modern CSS techniques including Flexbox, Grid, and responsive design',
    javascript: 'Become proficient in JavaScript and build interactive web applications',
    vue: 'Master Vue.js 3 and build modern single-page applications'
  }
  return descriptions[subject] || 'Learn web development fundamentals'
}

const getCourseModules = (subject) => {
  const modules = {
    html: ['HTML5 Semantic Elements', 'Forms and Validation', 'Accessibility Basics', 'SEO Fundamentals'],
    css: ['CSS3 Features', 'Flexbox Layout', 'CSS Grid', 'Responsive Design', 'Animations'],
    javascript: ['ES6+ Syntax', 'DOM Manipulation', 'Async Programming', 'API Integration', 'Error Handling'],
    vue: ['Vue 3 Basics', 'Composition API', 'Component Communication', 'Vue Router', 'State Management']
  }
  return modules[subject] || ['Course Module 1', 'Course Module 2', 'Course Module 3']
}
</script>
