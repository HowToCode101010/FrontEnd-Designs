<template>
  <div>
    <div>
      <!-- Header -->
      <div>
        <h1>Choose Your Learning Path</h1>
        <p>Master HTML, CSS, JavaScript, and Vue.js with our comprehensive courses</p>
        
        <!-- Billing toggle -->
        <div>
          <button @click="isAnnual = true">
            Yearly <span>-20%</span>
          </button>
          <button @click="isAnnual = false">
            Monthly
          </button>
        </div>
      </div>
      
      <!-- Pricing cards -->
      <div>
        <PricingCard
          :is-annual="isAnnual"
          plan-name="HTML & CSS Fundamentals"
          :price="{ yearly: 19, monthly: 25 }"
          description="Perfect for beginners starting their web development journey"
          :features="[
            'Complete HTML5 course',
            'CSS3 and Flexbox/Grid',
            'Responsive design principles',
            'Real-world projects',
            'Certificate of completion',
            'Lifetime access'
          ]"
        />
        
        <PricingCard
          :is-annual="isAnnual"
          :popular="true"
          plan-name="JavaScript Mastery"
          :price="{ yearly: 39, monthly: 49 }"
          description="Master modern JavaScript and build dynamic web applications"
          :features="[
            'ES6+ JavaScript features',
            'DOM manipulation',
            'Async/Await & Promises',
            'API integration',
            'Local storage & cookies',
            'debugging techniques',
            'Real projects portfolio',
            'Job interview prep'
          ]"
        />
        
        <PricingCard
          :is-annual="isAnnual"
          plan-name="Vue.js Complete"
          :price="{ yearly: 59, monthly: 75 }"
          description="Become a Vue.js expert with this comprehensive course"
          :features="[
            'Vue 3 Composition API',
            'Component architecture',
            'Vue Router & Pinia',
            'Vite build system',
            'Testing with Vitest',
            'Deployment strategies',
            'Full-stack projects',
            'Career guidance'
          ]"
        />
      </div>
      
      <!-- Course bundles -->
      <div>
        <h2>Complete Learning Bundles</h2>
        <div>
          <div>
            <h3>Frontend Developer Bundle</h3>
            <p>Complete HTML, CSS, JavaScript & Vue.js courses</p>
            <div>
              <span>$</span>
              <span>{{ isAnnual ? '99' : '129' }}</span>
              <span>/one-time</span>
            </div>
            <button>Get Full Bundle</button>
          </div>
          
          <div>
            <h3>All-Access Pass</h3>
            <p>Access to all current and future courses</p>
            <div>
              <span>$</span>
              <span>{{ isAnnual ? '149' : '199' }}</span>
              <span>/year</span>
            </div>
            <button>Start Learning</button>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'
import PricingCard from '../components/PricingCard.vue'

const isAnnual = ref(true)
</script>
